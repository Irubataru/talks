LATEXMK  := latexmk
LATEX    := xelatex
GNUPLOT  := gnuplot

FIGDIR   := figs
FIGTEX   := $(wildcard $(FIGDIR)/*.tex)
FIGPDF   := $(FIGTEX:.tex=.pdf)

PLOTDIR  := plts
PLOTSCR  := $(wildcard $(PLOTDIR)/*.p)
PLOTPDF  := $(PLOTSCR:.p=.pdf)

MAINTEX  := presentation.tex
MAINPDF  := $(MAINTEX:.tex=.pdf)
AUXTEX   := $(filter-out $(MAINTEX) $(FIGTEX),$(wildcard **/*.tex))

cd_and_clean = cd $(dir $(realpath $(1))); $(LATEXMK) -C $(notdir $(1))

.PHONY: clean cleanthesis

$(MAINPDF) : $(AUXTEX) $(MAINTEX) $(FIGPDF) $(PLOTPDF)
	$(LATEXMK) -pdf $(MAINTEX)

$(FIGPDF): %.pdf: %.tex
	cd $(dir $<); \
	$(LATEX) $(notdir $<)

$(PLOTPDF): %.pdf: %.p
	cd $(dir $<); \
	$(GNUPLOT) $(notdir $<); \
	sed -ie 's/\\SetUnicodeOption/\\usepackage{ucs}\n&/' $(notdir $(<:.p=.tex)); \
	$(LATEX) $(notdir $(<:.p=.tex))

clean: $(FIGTEX) $(MAINTEX)
	$(foreach file, $^, $(call cd_and_clean,$(file));)

cleanthesis: $(MAINTEX)
	$(LATEXMK) -C $(MAINTEX)
