]: " << fib[K] << endl;
        while (N - fib[K-1]*a >= 0 && (N - fib[K-1]*a) / fib[K] >= a) {
            if ((N - fib[K-1]*a) % fib[K] == 0) {
                ans++;
            }
            a++;
        }
        cout << ans << endl;
    }
}