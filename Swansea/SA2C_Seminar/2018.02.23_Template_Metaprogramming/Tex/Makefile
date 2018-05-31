
SRC  := introduction_to_template_metaprogramming.tex
PDF  := $(SRC:.tex=.pdf)
DEFS := $(wildcard defintions/*.tex)

TREE_DIR := input
TREE := $(TREE_DIR)/expr_tree.tex
TREE_GEN_SRC := code/00_ast_expr_template_gen.cpp
TREE_GEN_BIN := $(TREE_GEN_SRC:.cpp=)

$(PDF): $(SRC) $(DEFS) $(TREE)
	latexmk -xelatex -g $(SRC)

$(TREE): $(TREE_GEN_BIN) | $(TREE_DIR)
	./$(TREE_GEN_BIN)

$(TREE_GEN_BIN): $(TREE_GEN_SRC)
	clang++ -std=c++14 $< -o $@

$(TREE_DIR):
	mkdir -p $@

clean:
	rm $(TREE_GEN_BIN)
	rm -rf $(TREE_DIR)
	latexmk -C
