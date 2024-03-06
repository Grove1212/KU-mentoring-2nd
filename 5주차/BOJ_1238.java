import java.util.Arrays;
import java.util.Scanner;

public class BOJ_1238 // 백준 1238 - 다익스트라 [파티 문제]
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), M = sc.nextInt(), X = sc.nextInt();
        // N = 마을의 수, M = 도로의 수, X는 출발지로 선택한 마을

        int[][] dist = new int[N + 1][N + 1]; // dist = 각 마을의 최단거리 저장 2차원 배열

        for (int i = 1; i <= N; i++)
            Arrays.fill(dist[i], 1000000);

        for (int i = 0; i < M; i++) {
            int n1 = sc.nextInt(), n2 = sc.nextInt(), t = sc.nextInt();
            dist[n1][n2] = t;
        }


        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        //현재 i에서 j로 가는 최단 경로보다, i에서 k를 거쳐 k에서 j로 가는 경로가 더 짧은 경우를 확인
                        dist[i][j] = dist[i][k] + dist[k][j];
                        //만약 더 짧은 경로가 있다면, i에서 j로 가는 최단 경로를 업데이트 한다.
        int ans = 0;
        for (int i = 1; i <= N; i++)
            if (i != X)
                ans = Math.max(ans, dist[i][X] + dist[X][i]);
        // Math.max를 통해 최대값을 ans에 저장.
        //그후 ans 출력~
        System.out.println(ans);


    }
}
