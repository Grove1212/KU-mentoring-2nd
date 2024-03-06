import java.io.*;
import java.util.ArrayDeque;
import java.util.Queue;

public class BOJ_1941 { //BOJ_1941_소문난칠공주
    static char[][] arr = new char [5] [5];
    static boolean [] [] selected = new boolean[5][5];
    static int res = 0;

    static class Pair {
        int first;
        int second;

        public Pair(int first, int second){
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 5; i++){
            String tmp = br.readLine();
            arr[i] = tmp.toCharArray();
        } // 5 * 5 크기의 격자에서 학생들이 앉은 상태를 입력으로 받는다~
        // 각 행마다 한 줄씩 입력을 받아서 arr 배열에 저장한다.

        // 그뒤에 comb는 메인함수에서 -> res를 print한다.
        // 7명의 학생을 선택하는 모든 조합을 찾는다.
        comb(0,0);
        System.out.println(res);
    }
    private static void comb(int cnt, int start){ // start는 조합을 구할 때 시작하는 위치
        if(cnt == 7){ // cnt는 현재까지 선택된 학생의 수, if cnt가 7 -> bfs 함수 호출

            bfs();
            return;
        }
        for(int i = start; i < 25; i++){//start부터 24(5*5)칸까지 반복문 실행
            selected[i/5][i%5] = true;

            comb(cnt + 1, i+1);
            selected[i/5][i%5] = false; // 재귀호출이 종료 -> 현재위치 i를 선택 안함 -> false = 백트래킹
        }
    }

    private static void bfs(){
        Queue<Pair> q = new ArrayDeque<>();
        boolean [][] visited = new boolean[5][5];
        int [][] dir = new int [][] {{0,1}, {1,0},{0,-1},{-1,0}};
        boolean flag = false;

        for(int i = 0; i < 5; i++){
            for(int j=0; j < 5; i++){
                if(selected[i][j]){
                    flag = true;
                    q.add(new Pair(i,j));
                    visited[i][j] = true;
                    break;
                }
            }
            if (flag)
                break;
        }

        int sCnt = 0; // 다솜파
        int yCnt = 0; // 도연파


        while (!q.isEmpty()) {
            Pair tmp = q.poll();
            if (arr[tmp.first][tmp.second] == 'Y') {
                yCnt++;
            } else if (arr[tmp.first][tmp.second] == 'S') {
                sCnt++;
            }
            for (int i = 0; i < 4; i++) {
                int nextRow = tmp.first + dir[i][0];
                int nextCol = tmp.second + dir[i][1];

                if (check(nextRow, nextCol) && !visited[nextRow][nextCol] && selected[nextRow][nextCol]) {
                    q.add(new Pair(nextRow, nextCol));
                    visited[nextRow][nextCol] = true;
                }
            }
        }

        if (yCnt + sCnt == 7 && sCnt > yCnt)
            res++;
    }

    private static boolean check(int nextRow, int nextCol) {
        return nextRow >= 0 && nextRow < 5 && nextCol >= 0 && nextCol < 5;
    } // 0이상 5 미만인지 확인하여 범위내에 있는지 판단한다.
}
