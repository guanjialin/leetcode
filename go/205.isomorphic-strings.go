package main

import "fmt"

func isIsomorphic(s string, t string) bool {
	mS2T := make(map[byte]byte)
	mT2S := make(map[byte]byte)

	for i := 0; i < len(s); i++ {
		bs, ok1 := mS2T[s[i]]
		_, ok2 := mT2S[t[i]]

		if !ok1 && !ok2 {
			mS2T[s[i]] = t[i]
			mT2S[t[i]] = s[i]
		} else if bs != t[i] {
			return false
		}
	}

	return true
}

func main()  {
	fmt.Println(isIsomorphic("egg", "add"))
}