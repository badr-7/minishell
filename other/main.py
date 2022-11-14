#!/usr/bin/env python

from sys import stdin
from binarytree import Node

ERROR = "ERROR"
EOF_TOKEN = "EOF_TOKEN"
OP_OR = "OP_OR"
OP_PIPE = "OP_PIPE"
OP_AND = "OP_AND"
OP_RDR_OUT_APP = "OP_RDR_OUT_APP"
OP_RDR_OUT = "OP_RDR_OUT"
OP_HEREDOC = "OP_HEREDOC"
OP_RDR_IN = "OP_RDR_IN"
LPAREN = "LPAREN"
RPAREN = "RPAREN"
STRING = "STRING"

UNQUOTED = 1
SINGLE_QUOTED = 2
DOUBLE_QUOTED = 3

def switch_quote_mode(mode, c):
	if c == "'":
		if mode == SINGLE_QUOTED:
			return UNQUOTED
		if mode == UNQUOTED:
			return SINGLE_QUOTED
	elif c == '"':
		if mode == DOUBLE_QUOTED:
			return UNQUOTED
		if mode == UNQUOTED:
			return DOUBLE_QUOTED
	return mode

class Lexer:
	def __init__(self, line):
		self.line = line.replace("\n", "")
		self.pos = 0

	def advance(self, n):
		if len(self.line) >= n:
			self.pos += n
		else:
			self.pos += len(self.line)
		self.line = self.line[n:]

	def skip_spaces(self):
		l = len(self.line)
		l_stripped = len(self.line.lstrip())
		self.advance(l - l_stripped)

	def peek(self):
		self.skip_spaces()
		if len(self.line) == 0:
			return {"value": None, "type": EOF_TOKEN}
		if self.line.startswith("||"):
			return {"value": "||", "type": OP_OR}
		if self.line.startswith("|"):
			return {"value": "|", "type": OP_PIPE}
		if self.line.startswith("&&"):
			return {"value": "&&", "type": OP_AND}
		if self.line.startswith(">>"):
			return {"value": ">>", "type": OP_RDR_OUT_APP}
		if self.line.startswith(">"):
			return {"value": ">", "type": OP_RDR_OUT}
		if self.line.startswith("<<"):
			return {"value": "<<", "type": OP_HEREDOC}
		if self.line.startswith("<"):
			return {"value": "<", "type": OP_RDR_IN}
		if self.line.startswith("("):
			return {"value": "(", "type": LPAREN}
		if self.line.startswith(")"):
			return {"value": ")", "type": RPAREN}
		mode = UNQUOTED
		i = 0
		while i < len(self.line) and (mode != UNQUOTED or self.line[i] not in " \t\n|&()<>"):
			mode = switch_quote_mode(mode, self.line[i])
			i += 1
		if i == 0:
			return {
				"value": f"minishell: syntax error: unrecognized token at position {self.pos + 1}",
				"type": ERROR
			}
		if mode != UNQUOTED:
			return {
				"value": "minishell: syntax error: unexpected end of file",
				"type": ERROR
			}
		return {"value": self.line[:i], "type": STRING}

	def next(self):
		token = self.peek()
		if token["type"] == ERROR:
			raise Exception(token["value"])
		elif token["type"] != EOF_TOKEN:
			self.advance(len(token["value"]))
		return token

	def __iter__(self):
		return self

	def __next__(self):
		token = self.next()
		if token["type"] == EOF_TOKEN:
			raise StopIteration()
		return token

def parse_error(lexer):
	token = lexer.peek()
	if token["type"] == EOF_TOKEN:
		raise Exception("minishell: syntax error: unexpected end of file")
	if token["type"] == ERROR:
		raise Exception(token["value"])
	raise Exception(f"minishell: syntax error near unexpected token '{token['value']}'")

def parse_redirection(lexer):
	token = lexer.peek()
	if token["type"] not in [OP_RDR_IN, OP_RDR_OUT, OP_RDR_OUT_APP, OP_HEREDOC]:
		return False
	lexer.next()
	token = lexer.next()
	if token["type"] == STRING:
		return True
	parse_error(lexer)

def parse_cmd_elem(lexer):
	token = lexer.peek()
	if token["type"] == STRING:
		lexer.next()
		return True
	return parse_redirection(lexer)

def parse_cmd(lexer):
	count = 0
	elem = parse_cmd_elem(lexer)
	while elem:
		count += 1
		elem = parse_cmd_elem(lexer)
	if count:
		return Node("simple_cmd")
	return False

def parse_pipeline(lexer: Lexer):
	cmd = parse_cmd(lexer)
	if cmd:
		pipe = parse_pipe(lexer)
		if pipe:
			pipe.left = cmd
			return pipe
	return cmd

def parse_pipe(lexer):
	if lexer.peek()["type"] != OP_PIPE:
		return False
	lexer.next()
	pipeline = parse_pipeline(lexer)
	if pipeline:
		return Node("pipe", right=pipeline)
	parse_error(lexer)

def parse_line(line):
	lexer = Lexer(line)
	pipeline = parse_pipeline(lexer)
	token = lexer.peek()
	if token["type"] == EOF_TOKEN:
		return pipeline
	parse_error(lexer)

# for line in stdin:
# 	try:
# 		tree = parse_line(line)
# 		print(tree)
# 	except Exception as e:
# 		print(e)


try:
	tree = parse_line("echo test &")
	print(tree)
except Exception as e:
	print(e)
