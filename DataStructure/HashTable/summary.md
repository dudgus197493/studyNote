해시 테이블에 대한 생각 정리
    1. 기존 배열과 해시 테이블
        - 배열의 가장큰 장점은 데이터의 접근할때 주소(인덱스)연산을 통해 O(1)의 작은 비용으로 접근할 수 있다는 것이다.(임의 접근)
        - 하지만 데이터를 저장할때 인덱스 번호까지 기억하지 않으므로, 저장후 데이터를 찾을 일이 생겼을 때 임의 접근이 가능한 자료구조임에도      불구하고 탐색 알고리즘으로 추가 비용을 지불하고 데이터를 찾는다.
        - 해시 테이블은 배열의 이런점을 보완하고 임의접근의 장점을 살리기 위해 만들어졌다.
    2. 해시 테이블의 특징 (공간을 팔아 시간을 사다)
        - 해시 테이블은 데이터를 key값과 value를 한쌍으로 저장한다.
        - 입력받느 key값을 해싱(Hashfunc)하여 테이블 내의 주소를 계산하고 이 주소에 데이터를 담는다.
        - 똑같이 데이터를 찾을 때도 입력받은 키값을 해싱하여 데이터가 저장되어있는 주소로 접근한다.
    3. 해싱(HashFunc)
        1) 나눗셈법
            - 입력받은 key값을 테이블의 사이즈로 나눠 나머지를 구한다.
            - 이렇게 구한 나머지는 절대 테이블 사이즈를 넘길 수 없다. -> 인덱스를 초과하여 데이터를 저장하는 경우가 없어진다.
        2) 자릿수 접기
            - key값의 각 자릿수를 더해 새로운 값을 구한다.
            - ex) 8129335 -> 8 + 1 + 2 + 9 + 3 + 3 + 5 = 31
            - 문자의 경우에 많이 쓴다.
            - ex) Hello -> H(72) + e(101) + l(108) + l(108) + o(111) = 500
        - 자릿수 접기후 그값을 다시 테이블 사이즈로 나누거나 등, 여기에 적혀있지 않은 다른 많은 해시방법들이 있다.
    4. 충돌(Collision)
        - 서로 다른 입력 값에 대해 동일한 해시 값, 즉 해시 테이블 내의 동일한 주소를 반환할 가능성이 있다.
        - 설사 똑같은 해시 값이 아니더라도 해시 테이블 내의 일부 지역의 주소들을 집중적으로 반환하는 결과로 데이터들이 한 곳에 모이는 문제가       발생할 가능성이 있다. -> 클러스터(Cluster)
    5. 충돌 해결
        1. 개방해싱 (Open Hashing) - 실전에서 쓰지 않는다.
            - 해시 테이블의 주소 바깥에 새로운 공간을 할당하여 문제를 해결
        2. 폐쇄해싱 (Closed Hashing)
            - 처음에 주어진 해시 테이블 공간 안에서 문제를 해결