#include <bits/stdc++.h>
using namespace std;

#define int ll
#define fast_io cin.tie(0)->sync_with_stdio(0);
typedef long long ll;

mt19937_64 rng(82672890);

void rot90(vector<vector<int>>& grid, int n){
	auto aux = grid;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) aux[j][n-1-i] = grid[i][j];
	}
	grid = aux;
}


int32_t main() {
	fast_io;
	
	int caso = 0;
	while(caso < 333){
		int n; cin >> n;
		if(n == 3){
			while(1){
				int x = rng() % 511 + 1;
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						cout << ((x>>(3*i+j))&1);
					}
					cout << endl;
				}
				string s; cin >> s;
				if(s[0] == 'C') break;
				int zero; cin >> zero; assert(zero == 0);
			}
			caso++;
			continue;
		}

		else{

			// descobre a escondida
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i == 2 && j == 2) cout << 1;
					else cout << 0;
				}
				cout << endl;
			}
			
			string s; cin >> s;
			if(s[0] == 'C'){
				caso++;
				continue;
			}

			vector<string> grid(n-2);
			for(auto& l : grid) cin >> l;

			vector ans(3, vector<int>(3));
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					ans[2-i][2-j] = grid[i][j] - '0';
				}
			}

			vector gd(n, vector<int>(n));

			int soma = 0;
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) soma ^= ans[i][j];
			if(soma){
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						cout << 1;
					}
					cout << endl;
				}
				string bom;
				cin >> bom;
				assert(bom[0] == 'C');
				caso++;
				continue;
			}
			
			if(ans[0][0] + ans[0][2] + ans[2][0] + ans[2][2] >= 1){
				for(int i=0;i<4;i++){
					if(ans[2][2] == 0){
						rot90(ans, 3);
						continue;
					}
					// ans[2][2] == 1
					for(int j=2;j<n;j++){
						for(int k=2;k<n;k++){
							int c = 0;
							for(int dj = 0;dj<3;dj++){
								for(int dk= 0; dk<3; dk++){
									if(ans[dj][dk])  c ^= gd[j-2+dj][k-2+dk];
								}
							}
							if(!c) gd[j][k] = 1;
						}
					}
					for(int j=i;j<4;j++) rot90(gd, n);
					break;
				}
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						cout << gd[i][j];
					}
					cout << endl;
				}
				string bom;
				cin >> bom;
				assert(bom[0] == 'C');
				caso++;
				continue;
			}

			if((ans[1][0]  ^ ans[1][1] ^ ans[1][2]) == 1){

				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						cout << (i&1);
					}
					cout << endl;
				}
				string bom;
				cin >> bom;
				assert(bom[0] == 'C');
				caso++;
				continue;

			}

			if((ans[0][1]  ^ ans[1][1] ^ ans[2][1]) == 1){

				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						cout << (j&1);
					}
					cout << endl;
				}
				string bom;
				cin >> bom;
				assert(bom[0] == 'C');
				caso++;
				continue;

			}

			assert(ans[1][1] == 0);
			if(ans[0][1]){
				assert(ans[2][1]);

				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						cout << ((i%4) <= 1);
					}
					cout << endl;
				}
				string bom;
				cin >> bom;
				assert(bom[0] == 'C');
				caso++;
				continue;

			}
			else{
				assert(ans[1][0]);
				assert(ans[1][2]);

				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						cout << ((j%4) <= 1);
					}
					cout << endl;
				}
				string bom;
				cin >> bom;
				assert(bom[0] == 'C');
				caso++;
				continue;
			}
			assert(0);
		}
	}

}
