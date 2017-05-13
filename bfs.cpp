// あり本p.36
// 幅優先探索
// 幅優先探索の考え方
// 初期状態をqueueに入れ, その後, queueから状態を取り出し, そこから遷移できる全ての訪れたことのない状態をqueueに入れる

#include <bits/stdc++.h>
using namespace std;

static const int INF = 100000000;
static const int MAX_N = 100;

//状態を表すクラスpairの場合, typedefしておくと便利
typedef pair<int,int> P;

//入力
char maze[MAX_N][MAX_N+1];//迷路を表す文字列の配列
int N,M;
int sx,sy,gx,gy;

int d[MAX_N][MAX_N];//各点までの最短距離

//移動4方向のベクトル
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

//(sx,sy)->(gx,gy)への最短距離を求める
//たどり着けない場合はINF
int bfs(){
    queue<P> que;
    //全ての点をINFで初期化
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            d[i][j] = INF;
        }
    }
    //スタート地点をqueueに入れその点の距離を0にする
    que.push(P(sx,sy));
    d[sx][sy] = 0;

    //queueが空になるまでループ
    while(que.size()){
        //queueの先頭を取り出す
        P p = que.front();
        que.pop();
        //取り出してきた状態がゴールならば探索を終了
        if(p.first == gx && p.second ==gy)break;
        //移動4方向をループ
        for(int i=0;i<4;i++){
            int nx = p.first+dx[i],ny = p.second+dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]!='#' && d[nx][ny]==INF){
                //移動できるならqueueにいれその点の距離をpから距離+1で確定する
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second]+1;
            }
        }
    }
    return d[gx][gy];
}

int main(){
    cin>>N>>M;
    //INPUT
    for(int y=0;y<M;y++){
        for(int x=0;x<N+1;x++){
            scanf("%c",&maze[x][y]);
            if(maze[x][y]=='S'){
                sx=x;sy=y;
            }
            if(maze[x][y]=='G'){
                gx=x;gy=y;
            }
        }
    }
    int res = bfs();
    cout<<res<<endl;
    return 0;
}
