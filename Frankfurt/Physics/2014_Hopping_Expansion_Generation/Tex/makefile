PDFTEX=pdflatex
PLOT=gnuplot
LATEXMK=latexmk -pdf -pdflatex="pdflatex --shell-escape"
SUITETARGET=pdf

#Find the document containing \begin{document}
SRC=$(shell grep -l '^\\begin{document}' *.tex)

#Look for all files containing chapter, but not \begin{document}, and filter out appendix
EXTRAS=$(filter-out $(SRC),$(shell grep -r -l '\\chapter' *.tex))

TARG=$(SRC:.tex=.pdf)
#BIBFILE=$(shell ls *.bib)
#PLOTS=$(shell ls Plots/*.p)
#TEXPLOTS=$(filter-out $(PLOTS:.p=.tex),$(shell ls Plots/*.tex))
#PDFPLOTS=$(PLOTS:.p=.pdf)
#EDITPLOTS=$(TEXPLOTS:.tex=.pdf)

all : $(PDFPLOTS) $(TARG)

.PHONY : clean $(SUITETARGET)

$(TARG) : $(SRC) $(EXTRAS) $(PDFPLOTS) $(EDITPLOTS) $(BIBFILE)
	$(LATEXMK) $(SRC)
	@echo $(EXTRAS)
	
$(SUITETARGET) :  
	@make

#$(PDFPLOTS) : $(PLOTS)
	#cd Plots; \
	#$(PLOT) $(subst .pdf,.p,$(notdir $@)); \
	#$(PDFTEX) $(subst .pdf,.tex,$(notdir $@)); \
	#rm $(subst .pdf,.log,$(notdir $@))

#$(EDITPLOTS) : $(TEXPLOTS)
	#cd Plots; \
	#$(PDFTEX) $(subst .pdf,.tex,$(notdir $@))

clean :
	ls lattice* | grep -v *.tex | xargs rm -f
	rm -f *.log
	rm -f *.fls
