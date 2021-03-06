가변 배열에 대한 생각 정리

1. 배열과 가변배열
    - 일반적인 배열은 변수를 선언할 때 상수를 인자로 넣어야 한다. 변수를 넣게 되면 컴파일 할 때 메모리영역을 고정적으로 잡을 수 없기 때문이다.
    - 가변 배열은 변수를 선언할 때 자유메모리에 동적으로 메모리를 할당받기 때문에 배열이 가득차면 동적으로 배열크기를 늘릴 수도 있다.

2. 가변배열 특징
    - 장점
        1) 데이터가 줄줄이 연속되게 저장되어 있어서 인덱스(주소)연산으로 데이터에 쉽게 접근 가능하다. O(1)(데이터의 갯수에 상관없이 한번에 접근)
    - 단점
        1) 저장공간을 늘리려 할 때 [공간 재할당 -> 데이터복사 -> 기존공간 할당해제]라는 비용이 들어감
        2) 배열은 연속되어있기 때문에 배열데이터의 순서를 바꾸려 할 때 다른 모든 값의 자리를 한칸씩 밀거나 당겨야 한다.

3. 사용
    - 데이터의 갯수가 고정적이 삽입, 제거가 빈번하지 않고 참조를 위해 쓰일 때 사용하면 좋다.
