import java.util.*;

public class BOJ_1495 { // BOJ_1495_기타리스트
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();//연주할곡 N
        int S = sc.nextInt(); // 시작볼륨 S
        int M = sc.nextInt();   // 최대 볼륨 M
        int ans = -1;
        
        int vol[] = new int[M+1];
        int change[] = new int[N+1];
        
        for(int i=0; i<N; i++) change[i] = sc.nextInt();
        
        for(int i=0; i<M+1; i++) vol[i] = -1;
        
        vol[S] = 0;
        
        for(int i=1; i<N+1; i++){
			List<Integer> changer = new ArrayList<>();
            for(int j=0; j<M+1; j++){
                if(vol[j]==i-1){
                    int minus = j-change[i-1];
                    int plus = j+change[i-1];
                    
                    if(minus>=0){
                        changer.add(minus);
                    }
                    if(plus<=M){
                        changer.add(plus);
                    } 
                }
            }
            for(int k : changer) vol[k] = i;
        }
        
        for(int i=0; i<M+1; i++){
            if(vol[i]==N) ans = Math.max(ans, i);
        }
        
        System.out.println(ans);
      
    }
}