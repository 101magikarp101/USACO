size(2000,1500);
import fontsize;
defaultpen(fontsize(90pt));
pen p = 5+black;
real s = 7;
real d = 1.7;
real h = 1.5;
string[] labels = {"A","B","C"};
for (int i = 0; i < 3; ++i) {
    draw(circle((i*s,0),2),p);
    draw(ellipse((i*s-1,0),0.15,0.3),p);
    draw(ellipse((i*s-1.8,0),0.15,0.3),p);
    draw((i*s-d,h)--(i*s+d,h)--(i*s,5)--cycle,p);
    if (i==1) {
        fill((i*s-d,h)--(i*s+d,h)--(i*s,5)--cycle,white);
    } else {
        fill((i*s-d,h)--(i*s+d,h)--(i*s,5)--cycle,black);
    }
    label(labels[i],(i*s,-2),2*S);
}