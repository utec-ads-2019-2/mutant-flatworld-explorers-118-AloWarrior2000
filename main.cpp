#include <iostream>
#include <vector>

using namespace std;

char orientation[] = {'N', 'E', 'S', 'W'};
int corX[] = {0, 1, 0, -1};
int corY[] = {1, 0, -1, 0};

int main(){
    int xmax, ymax,x, y;
    char inicio;
    string orders;
    cin >> xmax >> ymax;
    vector<vector<bool> > scent(ymax + 1, vector<bool> (xmax + 1, false));

    while (cin >> x >> y >> inicio >> orders){
        int pos = 0;
        for (int i = 0; i < 4; ++i)
            if (inicio == orientation[i])
                pos = i;
        bool punto = false;
        for (char order : orders){
            if (order == 'R')
                pos = (pos + 1) % 4;
            else if (order == 'L')
                pos = (pos + 3) % 4;
            else{
                if ((x + corX[pos] == -1) || (x + corX[pos] == xmax + 1 ) || (y + corY[pos] == -1) || (y + corY[pos] == ymax + 1)){
                    if (!scent[y][x]){
                        scent[y][x] = punto = true;
                        break;
                    }
                }
                else{
                    x += corX[pos];
                    y += corY[pos];
                }
            }
        }
        cout << x << ' ' << y << ' ' << orientation[pos] << (punto ? " LOST" : "") << '\n';
    }


}