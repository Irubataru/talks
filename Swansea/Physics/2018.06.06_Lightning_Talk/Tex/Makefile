LATEXMK  := latexmk
LATEX    := xelatex -pdf

MAINTEX  := lightning_talk.tex
MAINPDF  := $(MAINTEX:.tex=.pdf)

FIGDIR   := figures
FIGTEX   := $(wildcard $(FIGDIR)/*.tex)
FIGPDF   := $(FIGTEX:.tex=.pdf)

STYLETEX := $(wildcard definitions/*.tex)
AUXTEX   := $(filter-out $(MAINTEX) $(FIGTEX),$(wildcard **/*.tex))

cd_and_clean = cd $(dir $(realpath $(1))); $(LATEXMK) -C $(notdir $(1))

.PHONY: clean cleanthesis

$(MAINPDF) : $(AUXTEX) $(MAINTEX) $(STYLETEX) $(FIGPDF)
	$(LATEXMK) -pdf $(MAINTEX)

$(FIGPDF): %.pdf: %.tex | $(STYLETEX)
	cd $(dir $<); \
	$(LATEX) $(notdir $<)

clean: $(MAINTEX) $(FIGTEX)
	$(foreach file, $^, $(call cd_and_clean,$(file));)
