set terminal tikz standalone
set output "rgeminoftH.tex"

set xlabel "$T$ [MeV]"
set ylabel "$\\langle \\sigma \\rangle$ [MeV]"

plot "RGEData/phaseTransMu0" notitle w l lt 1 lc -1
