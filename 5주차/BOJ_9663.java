import java.util.Scanner;

public class BOJ_9663 { // 백준 9663 - N-Queen
    public static int [] arr;
    public static int N;
    public static int count = 0;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        arr = new int [N];

        nQueen(0);
        System.out.println(count);
    }

    public static void nQueen(int depth){
    // 모든 원소를 다 채운 상태면 count 증가 및 return

        if(depth == N){
            count++;
            return;
        }

        for (int i = 0; i < N; i++){
            arr[depth] = i;
            // 놓을 수 있는 위치일 경우 재귀호출


            if(Possible(depth)){
                nQueen(depth + 1);
            }
        }
    }
    public static boolean Possible(int col){
        for(int i =0; i < col; i++){
        // 해당 열의 행과 i열의 행이 일치할경우 (같은 행에 존재할 경우)

            if(arr[col]==arr[i]){
                return false;
            }

            //  * 대각선상에 놓여있는 경우
            // * 열의 차와 행의 차가 같을 경우가 대각선에 놓여있는 경우
            else if (Math.abs(col - i) == Math.abs(arr[col] -arr[i])){ // Math.abs는 절대값을 구하는것.
                return false;
            }
        }

        return true;
    }

}