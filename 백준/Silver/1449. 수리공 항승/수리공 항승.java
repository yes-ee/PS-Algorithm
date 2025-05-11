import java.util.StringTokenizer;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int n, l, cnt;
    static int [] arr;
    static int s, e;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0 ; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        s = arr[0];
        e = s + l - 1;
        cnt = 1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] <= e) continue;
            s = arr[i];
            e = s + l - 1;
            cnt++;
        }
        System.out.println(cnt);

    }
}

