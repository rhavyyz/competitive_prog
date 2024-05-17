- K-th Beautiful String 
    - Ideia
        > Em suma, o que define a posicao na ordem lexicografica sao as posicoes dos 2 b`s, entao para achar a kezima string devemos achar essas posicoes. Vamos buscar as posicoes de forma invertida ja que desse jeito a, ao menos pra mim, fica mais simples de entender. Com posicoes invertidas quero dizer que as a ultima posicao da string teria o index 0, enquanto a primeira teria o index $n-1$
        > - aa $b_0b_1$  :  $b_0$ esta na posica 1, $b_1$ esta na posicao 0 
        >
        > Se escrevermos algumas strings em ordem lexicografica veremos algo em relacao a essas posicoes
        > - ...aaaaaa_bb 
        > - ...aaaaa_bab
        > - ...aaaaa_bba
        > - ...aaaa_baab
        > - ...aaaa_baba
        > - ...aaaa_bbaa
        > - ...aaa_baaab
        > - ...aaa_baaba
        > - ...aaa_babaa
        > - ...aaa_bbaaa
        > 
        > Com $b_0$ estando em 1 pode ser representada apenas a primeira string.
        >
        > Com $b_1$ estando em 2 podem ser representadas a 2 e 3 string .
        >
        > Com $b_1$ estando em 3 podem ser representadas da 4 ate a 6 string.
        >
        > Com $b_1$ estando em 4 podem ser representadas da 7 ate 10 string.
        > 
        > Fixando a posicao $b_0$ conforme as posicoes de $b_1$ crescem (em [0, $b_0-1$]), a colocacao na ordem aumenta dentro dos intervalos citados acima. Quando os dois b`s ficam lado a lado, significa que o maior numero de classificacao para uma posicao fixa de $b_0$ foi alcancado.
        >
        > Assim achamos a posicao de $b_0$ a partir do intervalo de cada posicao e posicionamos $b_1$ gerando uma exata colocacao. Definindo exatamente esses intervalos, quando $b_0$ esta na posicao $i$, podemos descobrir o intervalo de colocacoes possiveis usando a soma de gaus do seguinte modo
        >
        > - $ [ (1+i-1)*(i-1)/2 + 1, (i+1)*i/2] $
        >
        > (Observe nos exemplos acima que de fato os intervalos batem)
        >
        > O fim desse intervalo, ou seja, a ultima classificacao que pode ser gerada quando $b_0$ esta em $i$ acaba sendo aprenas a soma da quantidade de strings que puderam ser geradas ate o momento, assim sendo a soma de gaus de 1 ate i
        >
        > O inicio desse intervalo fechado a soma de gaus de 1 ate $i-1$ somado a 1 (ja que a primeira colocacao contida no intervalo associado a posicao $i$ e o a primeira apos o intervalo de $i-1$ )
        >
        > Achando a posicao de $b_0$ devemos agora posicionar $b_1$ da seguinte forma
        >
        >   - $b_1$ pos : k - incio do intervalo
        >
        > No codigo usei busca binaria para achar a posicao de $b_0$ e no final apenas desinverti as posicoes dos dois b`s

    - Codigo
        ```
            #include<iostream>
            using namespace std;

            #define int long long

            int n; 

            int gaus(int i)
            {
                return (1 + i) * i / 2;
            }

            int bb(int k)
            {
                int l = 1, r = n-1;

                while(l < r)
                {
                    int mid = (l+r)/2;

                    if(gaus(mid) == k)
                        return mid;
                    
                    if(gaus(mid) > k)
                        r = mid;
                    else
                        l = mid + 1;
                }

                return l;
            }

            void solve()
            {

                int k; cin >> n >> k;

                int b[2];
                b[0] = bb(k);

                int past = gaus(b[0]-1);

                b[1] = k-past-1;

                b[0] = n - 1 - b[0];
                b[1] = n - 1 - b[1];

                for(int i = 0; i < n; i++ )
                {

                    if(i == b[0] || b[1] == i )
                        cout << 'b';
                    else 
                        cout << 'a';
                }

                cout << endl;

            }

            signed main()
            {
                int t; cin >> t;

                while(t--)
                    solve();

                return 0;
            }
        ```