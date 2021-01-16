#!/usr/bin/gnuplot -persist
set xlabel "Length" font ",15"
set ylabel "u(x,t)" font ",15"
set tics font",30"

set term x11 0  #Creating a new window with ID 0
plot "trial0" using 1:3 w l lw 1.5 title "Analytical time step=0"
replot "trial0" using 1:2 w p lc rgb 'black' pt 9 title "Simulation time step=0" 


set term x11 1  #Creating a new window with ID 1
plot "trial100" using 1:3 w l lw 1.5 title "Analytical time step=100"
replot "trial100" using 1:2 w p lc rgb 'black' pt 9 title "Simulation time step=100" 

set term x11 2  #Creating a new window with ID 2
plot "trial500" using 1:3 w l lw 1.5 title "Analytical time step=500" 
replot "trial500" using 1:2 w p lc rgb 'black' pt 9 title "Simulation time step=500" 


set term x11 3  #Creating a new window with ID 3
plot "trial1000" using 1:3 w l lw 1.5 title "Analytical time step=1000" 
replot "trial1000" using 1:2 w p lc rgb 'black' pt 9 title "Simulation time step=1000" 


