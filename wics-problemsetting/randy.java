import java.util.*;
import java.io.*;

public class randy {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = Integer.parseInt(st.nextToken());
        }

        // min seeds to reach 1 after i blows
        long[] min = new long[n+1];
        for (int i = 0; i <= n; i++) {
            double c = 1;
            for (int j = i-1; j >= 0; j--) {
                c = Math.ceil(c * b[j] / a[j]);
                System.out.printf("c=%.18f\n", c);
                if (c > 1e18) break;
            }
            min[i] = (long) c;
        }
        System.out.println(Arrays.toString(min));

        int q = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < q; i++) {
            long m = Long.parseLong(st.nextToken());
            if (m == 0) {
                pw.println(0);
                continue;
            }
            int index = Arrays.binarySearch(min, m);
            if (index >= 0) {
                pw.println(index + 1);
            } else {
                index = ~index;
                if (index == n+1) {
                    pw.println(-1);
                } else {
                    pw.println(index);
                }
            }
        }

        pw.close();
    }
}
