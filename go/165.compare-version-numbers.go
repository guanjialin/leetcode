package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func compareVersion(version1 string, version2 string) int {
	ver1 := strings.Split(version1, ".")
	ver2 := strings.Split(version2, ".")
	lenV1 := len(ver1)
	lenV2 := len(ver2)
	maxLen := int(math.Max(float64(lenV1), float64(lenV2)))

	for i := 0; i < maxLen; i++ {
		v1 := 0
		v2 := 0

		if lenV1 > i {
			v1, _ = strconv.Atoi(ver1[i])
		}

		if lenV2 > i {
			v2, _ = strconv.Atoi(ver2[i])
		}
		
		if v1 > v2 {
			return 1
		} else if v2 > v1 {
			return -1
		}
	}

	return 0
}


func main() {
	fmt.Println(compareVersion("1.0.1", "1"))
}
