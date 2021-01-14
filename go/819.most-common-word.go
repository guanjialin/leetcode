package main

import (
	"fmt"
	"strings"
)

func mostCommonWord(paragraph string, banned []string) string {
	mBanned := make(map[string]struct{})
	punct := map[uint8]struct{} {
		'!': {},'?':{},',':{},';':{},'.':{}, ' ':{}, '\'':{},
	}

	for _, v := range banned {
		mBanned[v] = struct{}{}
	}

	left := 0
	right := 0
	ans := ""
	words := make(map[string]int)
	for right <= len(paragraph) {	// <= 主要是为了处理最后一个单词
		// 这一块不知道有没有优雅一点的写法
		ok1 := false
		if right == len(paragraph) {
			ok1 = true
		} else {
			_, ok1 = punct[paragraph[right]]
		}

		if ok1 {
			word := strings.ToLower(paragraph[left:right])
			if _, ok2 := mBanned[word]; word != "" && !ok2 {
				words[word]++
				if words[word] > words[ans] {
					ans = word
				}
			}

			left = right + 1	// 这里用 right + 1 要结合前面的 word != "" 看，同时也是为了避免符号后面有多个空格的情况
		}

		right++
	}

	return ans
}

func main() {
	fmt.Println(mostCommonWord("Bob. hIt, baLl", []string{"hit", "bob"}))
	fmt.Println(mostCommonWord("j. t? T. z! R, v, F' x! L; l! W. M; S. y? r! n; O. q; I? h; w. t; y; X? y, p. k! k, h, J, r? w! U! V; j' u; R! z. s. T' k. P? M' I' j! y. P, T! e; X. w? M! Y, X; G; d, X? S' F, K? V, r' v, v, D, w, K! S? Q! N. n. V. v. t? t' x! u. j; m; n! F, V' Y! h; c! V, v, X' X' t? n; N' r; x. W' P? W; p' q, S' X, J; R. x; z; z! G, U; m. P; o. P! Y; I, I' l' J? h; Q; s? U, q, x. J, T! o. z, N, L; u, w! u, S. Y! V; S? y' E! O; p' X, w. p' M, h! R; t? K? Y' z? T? w; u. q' R, q, T. R? I. R! t, X, s? u; z. u, Y, n' U; m; p? g' P? y' v, o? K? R. Q? I! c, X, x. r' u! m' y. t. W; x! K? B. v; m, k; k' x; Z! U! p. U? Q, t, u' E' n? S' w. y; W, x? r. p! Y? q, Y. t, Z' V, S. q; W. Z, z? x! k, I. n; x? z; V? s! g, U; E' m! Z? y' x? V! t, F. Z? Y' S! z, Y' T? x? v? o! l; d; G' L. L, Z? q. w' r? U! E, H. C, Q! O? w! s? w' D. R, Y? u. w, N. Z? h. M? o, B, g, Z! t! l, W? z, o? z, q! O? u, N; o' o? V; S! z; q! q. o, t! q! w! Z? Z? w, F? O' N' U' p? r' J' L; S. M; g' V. i, P, v, v, f; W? L, y! i' z; L? w. v, s! P?",
		[]string{"m","q","e","l","c","i","z","j","g","t","w","v","h","p","d","b","a","r","x","n"}))
}