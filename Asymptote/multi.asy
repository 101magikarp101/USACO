size(2000,1500);
import fontsize;
defaultpen(fontsize(30pt));
pen p = 1+black;
real x = 0;
real y = 0;
real vx = 20;
real vy = 20;
real d = 0.001;
real g = 1;
real max = -1;
//draw axes and tick marks and labels every 5 units
draw((0,0)--(0,30),p);
draw((0,0)--(100,0),p);
for (int i = 5; i < 100; i+=5) {
    draw((i,-0.5)--(i,0.5),p);
    label("$"+string(i)+"$",(i,-1),S,p);
}
for (int i = 5; i < 30; i+=5) {
    draw((-0.5,i)--(0.5,i),p);
    label("$"+string(i)+"$",(0,i),W,p);
}
for (int i = 0; i < 3700; ++i) {
    real a = x;
    real b = y;
    x+=vx*d;
    y+=vy*d;
    real ax = -g*x/(x^2+y^2)^1.5;
    real ay = -g*y/(x^2+y^2)^1.5-10;
    vx+=ax*d;
    vy+=ay*d;
    draw((a,b)--(x,y),p);
    if (y>0) {
        max = max(max,x);
    }
}
x = 0;
y = 0;
vx = 20;
vy = 20;
for (int i = 0; i < 4000; ++i) {
    real a = x;
    real b = y;
    x+=vx*d;
    y+=vy*d;
    vy-=10*d;
    draw((a,b)--(x,y),p);
}
label(string(max),(max,0),S,p);