#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const int maxt= 51;
int main() {
    int length, width, lp, rp, up, dp, x, y;
    cin >> length >> width;
    cin >> up>>dp  >>lp >>rp ;
    cin >> x >> y;
    double deltax=51/static_cast<double>(length);
    double deltay=51/static_cast<double>(width);
    double ratio = static_cast<double>(deltax) / static_cast<double>(deltay);
    double potential[maxt][maxt] = {0};
    for (int j = 0; j < width; j++) {
        potential[0][j] = up;
        potential[length - 1][j] = dp;}
    for (int i = 0; i < length; i++) {
        potential[i][0] = lp;
        potential[i][width - 1] = rp;}
    potential[0][0] = (up + rp) / 2.0;
    potential[0][width - 1] = (up + lp) / 2.0;
    potential[length - 1][0] = (dp + rp) / 2.0;
    potential[length - 1][width - 1] = (lp + dp) / 2.0;
    int maxiterations = 10000;
    double threshold = 0.0001;
    for (int it = 0; it < maxiterations; it++) {
        double changes = 0;
        double oldpotential[maxt][maxt];
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < width; j++) {
                oldpotential[i][j] = potential[i][j];
            }
        }
        for (int i = 1; i < length - 1; i++) {
            for (int j = 1; j < width - 1; j++) {
                potential[i][j] =
                        (oldpotential[i+1][j]+ oldpotential[i-1][j]+ ratio*ratio*oldpotential[i][j+1]+ oldpotential[i][j-1])
                        / (2.0+(2.0*ratio*ratio));
                double change = fabs(potential[i][j] - oldpotential[i][j]);
                if (change > changes) changes = change;
            }
        }
        if (changes < threshold) {
            break;
        }
    }
    cout  <<round(potential[y][x]) << endl;
    return 0;
}