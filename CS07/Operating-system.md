# Operating system

##### 2022.1.24

An operating system (OS) is system software that manages computer hardware, software resources, and provides common services for computer programs.

컴퓨터 하드웨어와 소프트웨어를 총체적으로 관리하는 핵심 소프트웨어

## Objectives

- [ ] 운영체제의 개념, 역할, 기능을 정리한다.
- [ ] 프로세스와 스레드 스케줄링을 이해하여 프로그램과 코드가 어떤 식으로 동작하는지 이해한다.

---

## Concept of Operating system

![image](https://user-images.githubusercontent.com/85419343/150718889-0d400b62-1ed4-4c15-9dc8-d917601a74d1.png)

- 컴퓨터 시스템은 위 그림과 같이 크게 user, software, hardware로 구성된다.
  - User : 어떤 일(작업)을 수행하고 컴퓨터를 사용하는 사람 혹은 장치, 다른 컴퓨터
  - Software : 컴퓨터가 기능을 수행하는 데 필요한 모든 프로그램. 시스템 소프트웨어, 유틸리티, 응용 프로그램 등으로 구성됨
    - System software : 컴퓨터 자원을 관리하고 응용 프로그램의 실행을 지원하여 컴퓨터를 제어하는 프로그램. 운영체제를 비롯해 장치 드라이버 등으로 구성된다.
    - Utility : 응용 프로그램보다 작지만 컴퓨터의 여러 처리 과정을 보조하여 시스템을 유지하고 성능을 개선하는 프로그램으로, 운영체제를 돕는 역할을 한다. 필요에 따라 사용자나 운영체제가 메모리 상주 프로그램으로 설치하기도 한다.
    - Application program : 특정 작업을 수행하려는 목적, 즉 어떤 문제를 해결하려고 사용자나 전문가가 만든 프로그램이다. 웹 브라우저, 워드 프로세서, 게임, 이미지 편집 프로그램, 은행 시스템 및 항공 예약 시스템 등이 이에 해당된다.
  - Hardware : 기본 연산 자원을 제공하는 프로세서(CPU), 메모리, 주변장치 등으로 구성된다.
- 운영체제는 여기서 **사용자가 하드웨어에 접근할 수 있는 유일한 수단**이다.
- 운영체제는 사용자가 응용 프로그램을 실행할 수 있는 기반 환경을 제공하여 컴퓨터를 편리하게 사용할 수 있도록 도와주고, 하드웨어를 효율적으로 사용할 수 있도록 다양한 기능을 제공하는 소프트웨어이다.
- 컴퓨터 시스템은 여러 사용자가 사용할 수 있으며, 다양한 응용 프로그램이 있을 수 있다.
  - 운영체제는 다양한 응용 프로그램이 하드웨어, 즉 컴퓨터 자원을 효율적으로 사용할 수 있도록 관리하고 조정하는 역할을 한다.

### 컴퓨터 자원을 관리하는 면에서 운영체제의 역할

#### 조정자

- 컴퓨터 시스템은 하드웨어와 소프트웨어, 그리고 이 둘 사이를 오가는 데이터로 운영된다.
- 운영체제는 이 운영 요소를 적절하게 사용할 수 있도록 제어하면서 사용자와 응용 프로그램 간에 통신할 수 있게 한다.
- 직접 다른 프로그램이 수행하는 특정 작업을 하는 것이 아니라, 이 작업을 할 수 있는 환경만 제공하는 조정자인 셈이다.
  - 예를 들어, 워드 프로세서 역할을 직접 하는 것이 아니라 워드 프로세서가 제 기능을 할 수 있도록 도와준다.

#### 자원 할당자나 관리자

- 운영체제는 각 응용 프로그램에 필요한 자원을 할당하는 자원 할당자이다.
- 컴퓨터 자원을 올바른 순서로 할당해야 원하는 업무를 제대로 수행할 수 있는데, 여러 응용 프로그램이 동일한 컴퓨터 자원을 요구하면 충돌이 발생할 수 있다.
- 이 때 운영체제는 컴퓨터 시스템을 공정하고 효율적으로 운영하려고 자원을 할당하는 방법을 결정하는 관리자 역할도 한다.

#### 응용 프로그램과 입출력장치 제어자

- 운영체제는 다양한 입출력장치와 응용 프로그램을 제어하는 역할을 한다.
- 컴퓨터 시스템을 부적절하게 사용하거나 오류가 발생하는 것을 방지하려고 하드웨어 사용을 조정하고 응용 프로그램의 실행을 제어한다.
- 특히 입출력장치를 동작시키고 통제하는 핵심 역할을 한다.

### 운영체제의 다양한 기능

- 이처럼 운영체제는 다양한 기능을 제공하여 여러 역할을 수행하기 때문에 정의도 다양하게 할 수 있다.
  - 보통은 "사용자와 하드웨어 사이의 중간 매개체로 **응용 프로그램의 실행을 제어하고, 자원을 할당 및 관리하며, 입출력 제어 및 데이터 관리와 같은 서비스를 제공**하는 소프트웨어"로 정의한다.

1. 하드웨어 및 사용자, 응용 프로그램, 시스템 프로그램 사이에서 인터페이스를 제공한다.
2. 프로세서, 메모리, 입출력장치, 통신장치 등 컴퓨터 자원을 효과적으로 활용하려고 조정, 관리한다.
3. 메일 전송, 파일 시스템 검사, 서버 작업 등 높은 수준의 서비스를 처리하는 응용 프로그램을 제어한다.
4. 다양한 사용자에게서 컴퓨터 시스템을 보호하려고 입출력을 제어하며 데이터를 관리한다.

## 운영체제의 기능

![image](https://user-images.githubusercontent.com/85419343/150721063-3adf958c-dc56-4578-8b7f-429af1a7e9e3.png)

- 운영체제가 하는 기능을 크게 자원 관리와 시스템 관리로 분류할 수 있다.
  - 자원 : 컴퓨터 시스템의 메모리, 프로세스, 장치, 파일 등
  - 시스템 : 시스템 보호(사용자 권한 부여), 네트워킹(통신), 명령 해석기(인터페이스)

---

### Reference

[Wikipedia | Operating system](https://en.wikipedia.org/wiki/Operating_system)
[IT CookBook, Operating system](https://www.hanbit.co.kr/store/books/look.php?p_code=B3239422381)
