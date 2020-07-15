# 2020 ALPS Summer study
### Written by jongbum

# Day 1. (2020.07.08)
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
# Day 2. (2020.07.15)
- **결과 값이 `int`범위 인지 `long long`범위인지** 반드시 확인 필요