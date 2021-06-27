#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAX = 1e5 + 10;

struct Edge{
	Edge* next;
	int To;
	int val;

	Edge(int _To = 0, int _val = 0, Edge* _next = NULL) {
		To = _To; val = _val; next = _next;
	}
	
	void Add(int, int);
};

struct Node {
	int pos;
	int val;

	Node(int _val  = 0, int _pos  = 0) {
		pos = _pos; val = _val;
	}

	friend bool operator<(Node x, Node y) {
		return x.val >  y.val;
	}
};

Edge H[2][MAX];
int d[2][MAX];
int n, m;
bool vis[2][MAX];

void Dijkstra(int);
 
int main() {
//	freopen("In.in", "r", stdin);
//	freopen("Out.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		H[0][u].Add(v, w);
		H[1][v].Add(u, w);
	}
	
	Dijkstra(0);
	Dijkstra(1);

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += d[0][i];
		ans += d[1][i];
//		printf("i = %d, d = %d %d\n", i, d[0][i], d[1][i]);
	}

	printf("%d\n", ans);

	return 0;
}

void Edge::Add(int To, int w){
	Edge* T = new Edge(To, w, next); next = T;
}

void Dijkstra(int x) {
	priority_queue<Node> q;
	memset(d[x], 0x7f, sizeof d[x]);
	d[x][1] = 0;
	q.push(Node(0, 1));

	while(!q.empty()) {
		int pos = q.top().pos, val = q.top().val; q.pop();
		if(vis[x][pos]) continue;
		vis[x][pos] = 1;

		for(Edge* i = H[x][pos].next; i; i = i->next) {
			int e = i->To, w = i->val;
			if(w + val < d[x][e]) {
				d[x][e] = w + val;
				q.push(Node(d[x][e], e));
			}
		}
	}
}
























