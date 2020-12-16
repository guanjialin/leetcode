package main

import (
	"fmt"
	"strings"
)

func wordPattern(pattern string, s string) bool {
	words := strings.Split(s, " ")
	if len(words) != len(pattern) {
		return false
	}

	mW2c := make(map[string]uint8)
	mC2w := make(map[uint8]string)

	for i, word := range words {
		_, ok1 := mW2c[word]
		w, ok2 := mC2w[pattern[i]]

		if !ok1 && !ok2 {
			mW2c[word] = pattern[i]
			mC2w[pattern[i]] = word
		} else if w != word {
			return false
		}
	}

	return true
}

func main()  {
	fmt.Println(wordPattern("abba", "dog cat cat dog"))
	fmt.Println(wordPattern("abba", "dog cat cat fish"))
	fmt.Println(wordPattern("aaaa", "dog cat cat dog"))
	fmt.Println(wordPattern("abba", "dog dog dog dog"))
}