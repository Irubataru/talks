set terminal tikz standalone
set output "rgetrans.tex"

set xrange [0:400]
set yrange [0:100]

set xlabel "$T\\,$[MeV]"
set ylabel "$\\sigma\\,$[MeV]"

#set key Le

set style line 1 lt 1 lc rgb "#304269"
set style line 2 lt 1 lc rgb "#F26101"
set style line 3 lt 2 lc rgb "#F26101"

plot "RGEData/phaseTransMu0" title "RGE" w l ls 2,\
"2FlData/minMu0h_new" title "MF" w l ls 1
#"3FlData/sxTWoot" every 2 title "$N_F=3,\\:\\sigma\\,$" w l ls 2,\
#"3FlData/syTWoot" every 2 title "$N_F=3,\\:\\sigma_{s}$" w l ls 3
