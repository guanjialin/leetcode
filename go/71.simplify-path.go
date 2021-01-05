package main

import (
	"strings"
)

func validate(str string) bool {
	return str != "" && str != ".." && str != "."
}

func simplifyPath(path string) string {
	ans := make([]string, 0)
	for _, v := range strings.Split(path, "/") {
		if validate(v) {
			ans = append(ans, v)
		} else if ".." == v && len(ans) > 0 {
			ans = ans[:len(ans) - 1]
		}
	}


	return "/" + strings.Join(ans, "/")
}