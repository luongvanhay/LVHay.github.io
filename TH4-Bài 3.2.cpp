#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Diem {
    int x, y;
};

bool hopLe(int x, int y, vector<vector<int>>& meCung, vector<vector<bool>>& daTham) {
    return (x >= 0 && x < meCung.size() && y >= 0 && y < meCung[0].size() && meCung[x][y] == 0 && !daTham[x][y]);
}

void BFS(vector<vector<int>>& meCung, Diem batDau, Diem ketThuc) {
    vector<vector<bool>> daTham(meCung.size(), vector<bool>(meCung[0].size(), false));
    queue<pair<Diem, vector<Diem>>> hangDoi;
    hangDoi.push({ batDau, {batDau} });
    daTham[batDau.x][batDau.y] = true;

    int huongX[] = { -1, 1, 0, 0 };
    int huongY[] = { 0, 0, -1, 1 };

    while (!hangDoi.empty()) {
        auto hienTai = hangDoi.front(); hangDoi.pop();
        Diem diemHienTai = hienTai.first;
        vector<Diem> duongDi = hienTai.second;

        if (diemHienTai.x == ketThuc.x && diemHienTai.y == ketThuc.y) {
            cout << "Duong di tim duoc: ";
            for (auto p : duongDi) {
                cout << "(" << p.x << ", " << p.y << ") ";
            }
            cout << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = diemHienTai.x + huongX[i];
            int ny = diemHienTai.y + huongY[i];
            if (hopLe(nx, ny, meCung, daTham)) {
                daTham[nx][ny] = true;
                vector<Diem> duongMoi = duongDi;
                duongMoi.push_back({ nx, ny });
                hangDoi.push({ {nx, ny}, duongMoi });
            }
        }
    }

    cout << "Khong tim duoc duong di." << endl;
}

int main() {
    vector<vector<int>> meCung = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    Diem batDau = { 0, 0 };
    Diem ketThuc = { 4, 4 };

    BFS(meCung, batDau, ketThuc);

    return 0;
}