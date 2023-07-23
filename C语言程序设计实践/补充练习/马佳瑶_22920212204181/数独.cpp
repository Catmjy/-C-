#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10;
// ������ֱ�����ַ���������������ַ����ķ�ʽ���룬ÿ�к����ڶ����ʱ��ᱻ�Զ�����һ�� '\0'�����������С N Ҫ���� 10�����ܱ��������

char g[N][N];

bool dfs(int x, int y) {
	if (y == 9) return true;                  // �����ǰ�����������һ�У���ֱ�ӷŻ� true
	if (x == 9) return dfs(0, y + 1);         // �����ǰ�����������һ�У��򷵻���һ�е�?��
	if (g[x][y] != '.') return dfs(x + 1, y); // �����ǰ���������֣�ֱ������

	bool st[N];                               // st ����浱ǰλ�� (x, y) ��������Щ��
	memset(st, false, sizeof st);             // Ҫ�ǵó�ʼ��~

	for (int i = 0; i < N - 1; i ++ )         // ��һ�¸���������Щ���ֱ������
		if (g[i][y] > 47 && g[i][y] < 58)
			st[g[i][y] ^ 48] = true;

	for (int i = 0; i < N - 1; i ++ )         // ��һ�¸���������Щ���ֱ������
		if (g[x][i] > 47 && g[x][i] < 58)
			st[g[x][i] ^ 48] = true;

	int sx = x / 3 * 3, sy = y / 3 * 3;       // �ҵ���ǰ�Ź�������Ͻ�λ��
	for (int i = sx; i < sx + 3; i ++ )       // ��һ�¸þŹ���������Щ���ֱ������
		for (int j = sy; j < sy + 3; j ++ )
			if (g[i][j] > 47 && g[i][j] < 58)
				st[g[i][j] ^ 48] = true;

	for (int i = 1; i < N; i ++ )             // ö�ٵ�ǰ�����������������
		if (!st[i]) {
			g[x][y] = i ^ 48;                 // ��������ô���ϣ���������һ��
			if (dfs(x + 1, y)) return true;
		}
	g[x][y] = '.';                            // ������������п������֣���û�п������֣���ô���ø��Ϊδ��״̬
	return false;                             // ������ false
}

int main() {
	for (int i = 0; i < N - 1; i ++ )
		scanf("%s", g[i]);                    // ���ַ�����ʽ����

	dfs(0, 0);                                // �� (0, 0) ��ʼ����

	for (int i = 0; i < N - 1; i ++) {
		putchar('\n');
		for (int j = 0; j < N - 1; j ++ )
			putchar(g[i][j]);                 // �����õ��������������ݱ�֤�н�����Ψһ�⣬���Բ��������κ������ֱ���������
	}
	return 0;
}
