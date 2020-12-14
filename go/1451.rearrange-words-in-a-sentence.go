package main

import (
	"fmt"
	"sort"
	"strings"
)

func arrangeWords(text string) string {
	words := strings.Split(text, " ")
	words[0] = strings.ToLower(words[0])
	sort.SliceStable(words, func(i, j int) bool {
		return len(words[i]) < len(words[j])
	})
	words[0] = strings.Title(words[0])


	return strings.Join(words, " ")
}

func main() {
	fmt.Println(arrangeWords("Leetcode is cool"))
	fmt.Println(arrangeWords("Keep calm and code on"))
	fmt.Println(arrangeWords("To be or not to be"))
}
