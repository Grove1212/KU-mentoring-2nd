import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class AlgorithmStudy01 {

   public static int[][] branch;
   public static boolean[] visit;
   public static Queue<Integer> queue;
   public static int N;
   public static int V;
   public static int M;

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      N = sc.nextInt();
      M = sc.nextInt();
      V = sc.nextInt();

      branch = new int[1001][1001];
      visit = new boolean[1001];

      for (int i = 0; i < M; i++) {
         int a = sc.nextInt();
         int b = sc.nextInt();
         branch[a][b] = branch[b][a] = 1;
      }

      dfs(V);
      System.out.println();

      Arrays.fill(visit, false);
      bfs(V);
   }

   public static void dfs(int start) {
      visit[start] = true;
      System.out.print(start + " ");
      for (int i = 1; i <= N; i++) {
         if (branch[start][i] == 1 && visit[i] == false) {
            dfs(i);
         }

      }
   }

   public static void bfs(int start) {
      queue = new LinkedList<Integer>();
      queue.add(start);
      visit[start] = true;
      System.out.print(start + " ");

      while (!queue.isEmpty()) {
         int temp = queue.poll();

         for (int i = 1; i < branch.length; i++) {
            if (branch[temp][i] == 1 && visit[i] == false) {
               queue.add(i);
               visit[i] = true;
               System.out.print(i + " ");
            }
         }
      }
   }
}