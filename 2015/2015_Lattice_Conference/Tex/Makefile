LATEXMK  := latexmk
LATEX    := xelatex
GNUPLOT  := gnuplot

FIGTEX   := $(wildcard Plots/*.tex) $(wildcard Graphs/*.tex)
FIGPDF   := $(FIGTEX:.tex=.pdf)

MAINTEX  := presentation.tex
MAINPDF  := $(MAINTEX:.tex=.pdf)
AUXTEX   := $(filter-out $(MAINTEX) $(FIGTEX),$(wildcard **/*.tex))

cd_and_clean = cd $(dir $(realpath $(1))); $(LATEXMK) -C $(notdir $(1))

.PHONY: clean

$(MAINPDF) : $(AUXTEX) $(MAINTEX) $(FIGPDF)
	$(LATEXMK) -pdf $(MAINTEX)

$(FIGPDF): %.pdf: %.tex
	cd $(dir $<); \
	$(LATEX) $(notdir $<)

clean: $(FIGTEX) $(MAINTEX)
	$(foreach file, $^, $(call cd_and_clean,$(file));)
