# First Steps for Option Pricing

Closed-form 공식과 Monte Carlo simulation을 이용해서 콜옵션 가격을 각각 계산하는 코드를 담고 있습니다.

### 디렉토리 별 설명

  * `linux`: `libpricing.so`를 생성해서 `main` 프로그램에서 사용하는 코드입니다.
  * `mingw`: `pricing.dll`을 생성해서 `main.exe` 프로그램에서 사용하는 코드입니다.
    * 본래 의도는 mingw를 이용해서 Windows 용 DLL을 생성해서 엑셀에서 사용할 수 있는지 확인해보는 것이었는데 잘 되지 않았습니다.
    * 그래서 Linux 환경에서 dll 생성 후 wine을 통해서 `main.exe`를 실행해 보는 것으로 마무리했습니다.
  * `windows/pricingDLL`: Visual Studio 프로젝트로 엑셀에서 사용할 수 있는 `pricingDLL.dll`을 생성하는 프로젝트 디렉토리입니다.
  * `windows/workbook.xlsm`: Visual Studio 프로젝트에서 build한 dll을 사용해보는 엑셀 파일입니다.
