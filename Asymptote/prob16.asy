size(2000,1500);
import fontsize;
defaultpen(fontsize(90pt));
pen p = 5+black;
draw((-0.5,-0.5)--(8.5,-0.5)--(8.5,8.5)--(-0.5,8.5)--cycle,white);
draw((0,0)--(8,0)--(8,8)--(0,8)--cycle,p);
string[] labels = {"$D$", "$B$", "$E$", "$A$", "$F$", "$C$", "$G$"};
for (int i = 1; i < 8; ++i) {
    draw((0,i)--(8,i),linetype(new real[] {2,2})+6);
    draw((i,0)--(i,8),linetype(new real[] {2,2})+6);
    label(labels[i-1],(i,0),S);
}