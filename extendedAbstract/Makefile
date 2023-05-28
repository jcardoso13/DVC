FILE = conference

all:
	pdflatex ${FILE}
	bibtex ${FILE}
	pdflatex ${FILE}
	pdflatex ${FILE}

clean:
	(rm -rf *.aux *.bbl *.blg *.glg *.glo *.gls *.ilg *.ist *.lof *.log *.lot *.nlo *.nls *.out *.toc)

veryclean:
	make clean
	rm -f *~ *.*%
	rm -f $(FILE).pdf $(FILE).ps
