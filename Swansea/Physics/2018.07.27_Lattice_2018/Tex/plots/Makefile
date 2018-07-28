TEX := $(wildcard *.tex)
PDF := $(TEX:%.tex=%.pdf)

.PHONY: all
all: $(PDF)

$(PDF): %.pdf: %.tex
	xelatex -pdf $<
