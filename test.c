/*
[ 수행과제 ]
프로젝트 마그라테아 멤버 소개

================================================================
1. 요구 사항 정리
    1 .환경 설정:
        ANSI C를 준수하며, GCC 컴파일러 버전 9.4.x 이상을 사용한다.
        크로스 플랫폼 지원 개발 환경을 구축한다.
    2. 프로그램 요구사항:
        두 가지 출력 형식을 구현한다:
            기본 형식: 모든 항목을 열로 나열.
            보너스 형식: 한 행에 두 열씩 나열.
        "경력"은 4바이트 2진수 표기로 표시한다.
        표준 출력 함수만 사용한다(printf).
    3. 제약 사항:
        모든 코드는 main() 함수 안에 작성한다.

================================================================
2. C 문법 학습
    1. printf로 출력:
        문자열, 정수, 2진수 출력 방법.
        줄바꿈(\n) 및 탭(\t) 활용.
        format 지정자.
    2. 2진수 변환 함수 구현:
        4바이트 정수를 2진수 문자열로 변환.
    3. 다국어 특성:
        한글, unicode
        font
    * 한글과 영어의 문자 폭 차이를 고려하려면 출력 문자열의 실제 길이를 계산하여 조정해야 합니다.
        한글은 폭 2로 간주하고, 영어는 폭 1로 간주합니다.
        문자열 길이를 계산한 후, 정렬된 출력 폭을 맞춥니다.

================================================================
[ 사전 학습 코드 예제 ]
1. printf를 이용한 문자열 출력:

#include <stdio.h>

int main() {
    printf("이름 | 아서 덴트\n");
    printf("성별 | 남\n");
    printf("전공 | 기계 공학\n");
    return 0;
}

2. 배열 사용법:
#include <stdio.h>

int main() {
    char name[] = "아서 덴트";
    printf("이름: %s\n", name);
    return 0;
}

3. 4바이트 정수를 2진수로 출력:
#include <stdio.h>

void print_binary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" "); // 8비트마다 공백 추가
    }
    printf("(2)\n");
}

int main() {
    int experience = 15;
    printf("경력: ");
    print_binary(experience);
    return 0;
}

*/

#include <stdio.h>
// #include <locale.h>

// 경력을 4바이트 2진수 문자열로 변환하는 함수
void print_binary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" "); // 8비트마다 공백 추가
    }
    // printf("(%d)", num);
}

void print_intro(char* intro) {
    // 소개 문장 출력 (마침표 이후 자동 줄 바꿈 처리)
    printf("소개 | ");
    for (int i = 0; intro[i] != '\0'; i++) {
        printf("%c", intro[i]);
        if (intro[i] == '.' && intro[i + 1] != '\0') {
            printf("\n     "); // 마침표를 만나면 자동 줄 바꿈 후 들여쓰기
        }
    }
    printf("\n=====================================================================\n");
}

int main() {
    // setlocale(LC_ALL, "ko_KR.UTF-8");

    // 출력 시작
    printf("[마그라테아] \u2665\u2665 프로젝트 멤버 소개 ♥♥\n");
    printf("=====================================================================\n");

    // 아서 덴트
    printf("이름 | %-15s 성별 | %s\n", "아서 덴트", "남"); 
    printf("전공 | %-15s 경력 | ", "기계 공학");
    print_binary(15);
    printf("(15)년\n");
    printf("역할 | %-15s 기술 | %s\n", "아키텍트", "C/C++, 자바, 스프링, 파이썬, 머신러닝/딥러닝");
    printf("---------------------------------------------------------------------\n");
    // char *intro = "실리콘 밸리에서 SNS, 핀테크, HR, 미디어 등의 다양한 프로젝트에 참여하며 경력을 쌓았습니다. 성공과 실패를 겪으며 얻게된 깨달음을 여러분과 나누고 싶습니다.";
    // print_intro(intro);
    printf("소개 | 실리콘 밸리에서 SNS, 핀테크, HR, 미디어 등의 다양한 프로젝트에 참여하며 경력을 쌓았습니다.\n");
    printf("      성공과 실패를 겪으며 얻게 된 깨달음을 여러분과 나누고 싶습니다.\n");
    printf("=====================================================================\n");

    // 김영진
    printf("이름 | %-15s 성별 | %-5s\n", "김영진", "남");
    printf("전공 | %-15s 경력 | ", "컴퓨터 공학");
    print_binary(2);
    printf("(2)년\n");
    printf("역할 | %-15s 기술 | %s\n", "개발자", "C#, 파이썬, 자바스크립트, 리액트, 코틀린");
    printf("---------------------------------------------------------------------\n");
    // 동적 할당이 아니라면 원래 문자열을 해제할 방법이 없습니다.
    // 이 문제는 심각한 메모리 누수로 이어지지는 않지만, 불필요한 문자열 리터럴이 쌓이게 됩니다.
    // intro = "최근에 MAUI 프레임워크로 진행한 개인 자산 관리 프로젝트에서 소프트웨어 개발에 엄청난 매력을 느꼈습니다. 나의 코드로 현실의 문제를 해결한다니! 마그라테아를 성공적으로 개발하는 것은 저의 버킷 리스트 중 하나가 되었습니다.";
    // print_intro(intro);
    // char* intro2 = "최근에 MAUI 프레임워크로 진행한 개인 자산 관리 프로젝트에서 소프트웨어 개발에 엄청난 매력을 느꼈습니다. 나의 코드로 현실의 문제를 해결한다니! 마그라테아를 성공적으로 개발하는 것은 저의 버킷 리스트 중 하나가 되었습니다.";
    // print_intro(intro2);
    printf("소개 | 최근에 MAUI 프레임워크로 진행한 개인 자산 관리 프로젝트에서 소프트웨어 개발에 엄청난 매력을 느꼈습니다.\n");
    printf("      나의 코드로 현실의 문제를 해결한다니! 마그라테아를 성공적으로 개발하는 것은 저의 버킷 리스트 중 하나가 되었습니다.\n");
    printf("=====================================================================\n");

    // 임원철
    printf("이름 | %-15s 성별 | %-5s\n", "임원철", "남");
    printf("전공 | %-15s 경력 | ", "전자 공학");
    print_binary(1);
    printf("(1)년\n");

    printf("역할 | %-15s 기술 | %s\n", "DBA", "자바, PHP, Mongo DB, MS SQL, MySQL");
    printf("---------------------------------------------------------------------\n");
    // char* intro3 = "애플리케이션은 결국 데이터를 다루는 방식을 구현한 것이라고 생각합니다. 대학에서 컴퓨터 공학과의 빅데이터 과목을 수강하며 데이터 플랫폼에 관해 매력을 느꼈습니다. 이번 프로젝트의 성공 여부는 데이터에 달렸다고 생각합니다. 마그라테아에서 다룰 데이터를 생각하면 벌써 부터 흥분됩니다.";
    // print_intro(intro3);    
    printf("소개 | 애플리케이션은 결국 데이터를 다루는 방식을 구현한 것이라고 생각합니다.\n");
    printf("      대학에서 컴퓨터 공학과의 빅데이터 과목을 수강하며 데이터 플랫폼에 관해 매력을 느꼈습니다.\n");
    printf("      이번 프로젝트의 성공 여부는 데이터에 달렸다고 생각합니다. 마그라테아에서 다룰 데이터를 생각하면 벌써부터 흥분됩니다.\n");
    printf("=====================================================================\n");

    // 유고은
    printf("이름 | %-15s 성별 | %s\n", "유고은", "여");
    printf("전공 | %-15s 경력 | ", "경영 정보");
    print_binary(1);
    printf("(1)년\n");

    printf("역할 | %-15s 기술 | %s\n", "클라우드", "자바, PowerShell, Azure, AWS, GCP");
    printf("---------------------------------------------------------------------\n");
    // char* intro4 = "김영진님과 함께 프로젝트를 진행했으며 클라우드 아키텍처 구현을 담당했습니다. 학창시절 클라우드에 매력을 느껴 마이크로소프트 Azure에 빠져들었는데, 깊이 탐구하다보니 다른 퍼블릭 클라우드도 어렵지 않게 이해할 수 있었습니다. 마그라테아의 클라우드 아키텍처를 내 손으로 꼭 완성시키고 싶습니다.";    
    // print_intro(intro4);
    printf("소개 | 김영진님과 함께 프로젝트를 진행했으며 클라우드 아키텍처 구현을 담당했습니다.\n");
    printf("      학창시절 클라우드에 매력을 느껴 마이크로소프트 Azure에 빠져들었는데, 깊이 탐구하다보니 다른 퍼블릭 클라우드도 어렵지 않게 이해할 수 있었습니다.\n");
    printf("      마그라테아의 클라우드 아키텍처를 내 손으로 꼭 완성시키고 싶습니다.\n");
    printf("=====================================================================\n");

    // 서혜경
    printf("이름 | %-15s 성별 | %s\n", "서혜경", "여");
    printf("전공 | %-15s 경력 | ", "정치외교");
    print_binary(0);
    printf("(0)년\n");
    printf("역할 | %-15s 기술 | %s\n", "개발자", "파이썬, 스위프트, 코틀린, Node.js, 피그마");
    printf("---------------------------------------------------------------------\n");
    // char* intro5 = "학부과정에서 과제로 프로젝트는 많이 진행해봤지만, 기업의 사활이 걸린 실전 프로젝트는 제 인생의 첫 경험입니다. 이 프로젝트에 참여하게 되어 기대도 많이 되는 한편으로, 제가 잘할 수 있을까 염려가 되기도 합니다. 마그라테아 프로젝트에 관해 들었을 때 제 속에서 이 프로젝트는 인생을 걸고 싶다는 생각을 했습니다. 링크드인을 통해 이미 아서님의 명성을 접했던 터라, 이번 프로젝트에 함께할 수 있어서 영광입니다.";
    // print_intro(intro5);
    printf("소개 | 학부과정에서 과제로 프로젝트는 많이 진행해봤지만, 기업의 사활이 걸린 실전 프로젝트는 제 인생의 첫 경험입니다.\n");
    printf("      이 프로젝트에 참여하게 되어 기대도 많이 되는 한편으로, 제가 잘할 수 있을까 염려가 되기도 합니다.\n");
    printf("      마그라테아 프로젝트에 관해 들었을 때 제 속에서 이 프로젝트는 인생을 걸고 싶다는 생각을 했습니다.\n");
    printf("      링크드인을 통해 이미 아서님의 명성을 접했던 터라, 이번 프로젝트에 함께할 수 있어서 영광입니다.\n");
    printf("=====================================================================\n");

    return 0;
}