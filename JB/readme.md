# 2020 ALPS Summer study
### Written by jongbum
해당 readme 파일은 스터디를 진행하면서 알게된 문법, STL 정보들을 수집하여 복습, 확인하기 위해 작성됨
# Week 1. (2020.07.08)
- Visual studio code를 통한 C/C++ 개발 환경 새로 설정
    - 단축키 정보
    - 컴파일 : (Ctrl)+(Alt)+(C)
    - 실행 : (Ctrl)+(Alt)+(R)
    - 디버깅 : (Ctrl)+(Alt)+(P) > "launch.json 열기" > (F5)로 디버깅 시작
- `cin.getline()`과 `std::getline()` 구분하기
    - `cin.getline(char[], length)` : char[]에만 가능
    - `std::getline(I/O, string, [\n])` : string에 가능하고, 어느 문자 이전까지 자를지 선택가능
- pair 또는 tuple에서 `{first, second}`를 사용하면 `make_pair`를 사용하지 않아도 됨(C++14)
- 3015_오아시스 재결합 문제는 다시 한번 코드를 보고 이해할 필요가 있음
# Week 2. (2020.07.15)
- **결과 값이 `int`범위 인지 `long long`범위인지** 반드시 확인 필요
- 큐의 크기를 고정하여 Sliding window를 구현할 수 있음
- `priority_queue`에서 가중치를 음수로 하면 역순으로 구성됨 (ex. 다익스트라)
- `getline`을 이용한 string tokenizer 구현 방법
```cpp
// data : raw_data
// token : data를 tokenize한 token들을 갖게될 변수
// delimiter : token 구분자
vector<string> tokenize_getline(const string& data, const char delimiter = ' ') {
	vector<string> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		result.push_back(token);
	}
	return result;
}
```
- `strtok`을 이용해서 char[]을 tokenize 가능
```cpp
    char str[] = "Geeks-for-Geeks"; 

    // Returns first token  
    char *token = strtok(str, "-"); 

    // Keep printing tokens while one of the 
    // delimiters present in str[]. 
    while (token != NULL) 
    { 
        printf("%s\n", token); 
        token = strtok(NULL, "-"); 
    } 
```
- minheap을 구성하는 방법은 `priority_queue<int, vector<int>, greater<int>>`
- maxheap은 기존의 `priority_queue<int>`로 구현 가능
- priority_queue의 내부 힙은 이진 트리 구조로 되어있기 때문에 같은 높이에 있는 값 간의 대소는 비교 되지 않음(pop시 일정함은 보장)
- O(nlogn)만에 모든 경우에서 중간값을 구하는 경우는 minheap과 maxheap을 유지하여 중간값을 기준으로 분할하여 저장
- 중간값보다 작은 값은 maxheap에, 큰 값은 minheap에 저장한다.
- 매 삽입시마다 maxheap의 최댓값과 minheap의 최솟값을 비교하여, 최댓값이 최솟값보다 큰 경우 자리를 바꿔준다.

# Week 3. (2020.07.22)
- *특정 T/C에 대한 분석은 코드를 부분으로 나눠서 디버깅 작업을 진행한다*
- contaniner iteration 도중 erase 작업은 Index을 추적하기 어렵게 함
    - 기본적으로 다중 반복문에서는 erase 후 내부 반복문은 `break`해야함
- real-time 정렬이 필요한 경우 heap, 불필요한 경우 sort 이용