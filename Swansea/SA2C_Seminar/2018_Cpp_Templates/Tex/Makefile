
SRC := introduction_to_cpp_templates.tex
PDF := $(SRC:.tex=.pdf)

$(PDF): $(SRC)
	latexmk -xelatex $<

clean:
	latexmk -C
