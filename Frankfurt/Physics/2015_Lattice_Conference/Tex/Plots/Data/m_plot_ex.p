set term tikz standalone solid font ",15"
set xtics 0.001
set xrange [0.996:1.001]
set key top left
set xlabel '$\mu_B / m_B$'
set ylabel '$ n_B / m_B^3 $'
set output 'continuum-extrapolated-density.tex'
plot 'analytic.txt' u ($1):(($2+$6)/2):($3+$7+sqrt(($6-$2)**2)) w errorbars t '$analytical$','langevin.txt' u ($1):(($2+$6)/2):($3+$7+sqrt(($6-$2)**2)) w errorbars t '$simulated$'
