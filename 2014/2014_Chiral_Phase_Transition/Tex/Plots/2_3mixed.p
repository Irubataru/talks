set terminal tikz standalone
set output "2_3mixed.tex"

set xlabel "$\\mu$ [MeV]"
set ylabel "$T$ [MeV]"

set yrange [0:160]
set xrange [0:330]

set style line 1 lt 1 lc rgb "#304269"
set style line 2 lt 1 lc rgb "#F26101"
set style line 3 lt 2 lc rgb "#F26101"

plot "2FlData/phaseGudrun" every ::52 title "$m_{\\sigma} = 450$ MeV" w l lc rgb "#304269" lt 1,\
"2FlData/phaseGudrun" every::::52 notitle w l lc rgb "#304269" lt 5,\
"2FlData/phaseGudrun" every ::52::52 notitle w p pt 7 lc rgb "#304269",\
"2FlData/phaseMs600" every ::76 title "$m_{\\sigma} = 600$ MeV" w l lc rgb "#F26101" lt 1,\
"2FlData/phaseMs600" every ::::76 notitle w l lc rgb "#F26101" lt 5,\
"2FlData/phaseMs600" every ::76::76 notitle w p pt 7 lc rgb "#F26101",\
"3FlData/phaseMs450" every ::91 smooth csplines notitle w lp lc rgb "#304269" lt 1 pt 10 pi 8,\
"3FlData/phaseMs450" every::::91 smooth csplines notitle w lp lc rgb "#304269" lt 5 pt 10 pi 8,\
"3FlData/phaseMs450" every ::91::91 notitle w p pt 7 lc rgb "#304269",\
"3FlData/phaseMs600" every ::123 smooth csplines notitle w lp lc rgb "#F26101" lt 1 pt 10 pi 12,\
"3FlData/phaseMs600" every ::::123 smooth csplines notitle w lp lc rgb "#F26101" lt 5 pt 10 pi 8,\
"3FlData/phaseMs600" every ::123::123 notitle w p pt 7 lc rgb "#F26101",\
