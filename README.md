# OOP C++

Repository bài tập môn Lập trình hướng đối tượng bằng C++, sử dụng **VS Code**, **MinGW-w64** và **clang-format**.

Mục tiêu của repository:

- Clone về máy mới và thiết lập nhanh.
- Không cần sửa source code để đọc dữ liệu từ file.
- Tự động format C++ khi lưu file.
- Hỗ trợ bài tập có một hoặc nhiều file `.cpp`.
- Không đưa file build vào GitHub.

## Yêu cầu

Cài sẵn các chương trình sau và thêm vào `PATH`:

- [Git](https://git-scm.com/)
- [Visual Studio Code](https://code.visualstudio.com/)
- Python 3
- MinGW-w64, bao gồm `g++` và `gdb`

Kiểm tra compiler:

```powershell
g++ --version
gdb --version
python --version
```

## Thiết lập sau khi clone

Mở PowerShell tại thư mục repository và chạy:

```powershell
.\setup.ps1
```

Script sẽ:

1. Kiểm tra Python và `g++`.
2. Tạo môi trường Python cục bộ trong `.tools`.
3. Cài `clang-format` bằng pip.
4. Cài extension `ms-vscode.cpptools` nếu VS Code CLI khả dụng.

Nếu PowerShell chặn việc chạy script, chỉ áp dụng policy cho lần chạy hiện tại:

```powershell
powershell -ExecutionPolicy Bypass -File .\setup.ps1
```

Sau khi setup xong, mở **thư mục repository gốc** bằng VS Code, không chỉ mở riêng thư mục `T1_2`.

## Cấu trúc thư mục

```text
OOP_C++/
├── .vscode/
│   ├── extensions.json
│   ├── launch.json
│   ├── settings.json
│   └── tasks.json
├── scripts/
│   └── build.ps1
├── T1_2/
│   ├── Ex11/
│   │   ├── ex1_1.cpp
│   │   └── ex1_1.h
│   ├── Ex24/
│   │   ├── ex2_4.cpp
│   │   ├── fraction.cpp
│   │   └── fraction.h
│   └── ...
├── .clang-format
├── .gitignore
├── input.txt
├── setup.ps1
└── README.md
```

Mỗi thư mục bài tập nên chứa các file `.cpp` và `.h` liên quan đến cùng một chương trình. Ví dụ, tất cả file `.cpp` trong `T1_2/Ex24/` sẽ được compile chung.

## Build và chạy bài đang mở

Mở một file `.cpp` trong thư mục bài tập, sau đó:

- Nhấn `Ctrl+Shift+B`.
- Chọn task **C++: Build and run active exercise** nếu VS Code hỏi.

Task sẽ:

1. Tìm tất cả file `.cpp` trong cùng thư mục với file đang mở.
2. Compile bằng `g++`.
3. Tạo file chạy tại:

```text
<thư mục bài>/build/program.exe
```

4. Chạy chương trình với input được redirect từ:

```text
${workspaceFolder}/input.txt
```

Vì vậy source code chỉ cần dùng `cin` bình thường:

```cpp
#include <iostream>

int main() {
    int x;
    std::cin >> x;
    std::cout << x << '\n';
}
```

Không cần dùng:

```cpp
freopen(...);
```

hoặc:

```cpp
std::ifstream fin(...);
```

## Build bằng PowerShell

Có thể gọi script trực tiếp:

```powershell
.\scripts\build.ps1 -SourceFile .\T1_2\Ex24\ex2_4.cpp
```

Build và chạy với `input.txt`:

```powershell
.\scripts\build.ps1 `
    -SourceFile .\T1_2\Ex24\ex2_4.cpp `
    -Run
```

Script tự compile toàn bộ file `.cpp` cùng thư mục, nên bài có nhiều file được hỗ trợ mà không cần liệt kê thủ công.

## Format code

Repository sử dụng Google Style thông qua file `.clang-format`.

Khi mở file C++ và nhấn `Ctrl+S`, VS Code sẽ tự format trước khi lưu.

Format thủ công bằng PowerShell:

```powershell
.\.tools\Scripts\clang-format.exe -i .\T1_2\Ex24\ex2_4.cpp
```

Nếu chưa chạy `setup.ps1`, hãy chạy setup trước để cài `clang-format`.

## Debug

Mở file `.cpp` cần debug và nhấn `F5`. VS Code sẽ:

1. Build bài đang mở.
2. Khởi chạy chương trình bằng GDB.

Đặt breakpoint bằng cách bấm vào lề trái của dòng code.

Để chạy chương trình có input tự động từ `input.txt`, dùng task `C++: Build and run active exercise` bằng `Ctrl+Shift+B`.

## Extension tối thiểu

Repository chỉ khuyến nghị extension:

- `ms-vscode.cpptools`

Extension này cung cấp:

- IntelliSense.
- Compile/debug C++.
- Tích hợp clang-format.
- Phát hiện lỗi compiler.

Danh sách extension được lưu trong `.vscode/extensions.json`.

## File không đưa lên GitHub

`.gitignore` loại bỏ các file sinh ra trong quá trình làm bài:

```text
build/
*.exe
*.o
*.obj
.tools/
```

Do đó chỉ cần commit source code, tài liệu và cấu hình; các file build sẽ được tạo lại trên từng máy.

## Thêm bài tập mới

Ví dụ tạo bài mới:

```text
T1_3/
└── Ex01/
    ├── main.cpp
    ├── Student.cpp
    └── Student.h
```

Mở `main.cpp` trong VS Code rồi nhấn `Ctrl+Shift+B`. Script sẽ tự tìm `main.cpp` và `Student.cpp`, sau đó compile chung.

## Dùng repository làm khung cho người khác

Khung cấu hình này **không phụ thuộc vào tên thư mục hoặc tên file bài tập**. Ví dụ, hai cấu trúc sau đều được hỗ trợ:

```text
T1_2/Ex24/
├── ex2_4.cpp
├── fraction.cpp
└── fraction.h
```

```text
Week03/Fractions/
├── main.cpp
├── Fraction.cpp
└── Fraction.h
```

Khi mở một file `.cpp`, `scripts/build.ps1` sẽ lấy tất cả file `.cpp` nằm **cùng thư mục với file đang mở**. Vì vậy tên thư mục có thể khác nhau, nhưng mỗi thư mục bài nên đại diện cho một chương trình độc lập.

### Cách chia sẻ khuyến nghị

Nếu muốn bạn bè có một bản riêng, trên GitHub nên bật **Template repository** cho repository này. Bạn của bạn chọn:

```text
Use this template → Create a new repository
```

Sau đó họ clone repository mới của họ về máy và chạy:

```powershell
.\setup.ps1
```

Cách này giữ lại toàn bộ khung:

- `.vscode/`
- `.clang-format`
- `.gitignore`
- `scripts/build.ps1`
- `setup.ps1`
- `end-session.ps1`
- `README.md`

nhưng repository GitHub, lịch sử commit và quyền push sẽ thuộc về người bạn đó.

### Nếu chỉ muốn lấy khung, không lấy bài của bạn

Có thể tạo một repository riêng tên như `cpp-study-template`, chỉ giữ các file cấu hình:

```text
cpp-study-template/
├── .vscode/
├── scripts/
├── .clang-format
├── .gitignore
├── end-session.bat
├── end-session.ps1
├── input.txt
├── README.md
└── setup.ps1
```

Bạn bè tạo repository riêng từ template này, rồi tự thêm các thư mục bài tập với tên tùy ý.

### Cách không nên dùng

Không nên để bạn bè clone trực tiếp repository cá nhân của bạn rồi chạy `git push`, vì remote mặc định sẽ trỏ về repository của bạn. Nếu đã clone trực tiếp, cần đổi remote trước khi push:

```powershell
git remote set-url origin https://github.com/<username>/<repo-cua-ban>.git
git remote -v
```

## Giới hạn hiện tại

- Mỗi thư mục bài chỉ nên có một chương trình; mọi `.cpp` trong thư mục đó sẽ được compile chung.
- Script chưa tự phân biệt nhiều chương trình độc lập nằm trong cùng một thư mục.
- Cấu hình hiện tại dành cho Windows, PowerShell và MinGW-w64.
- Bạn bè cần có `g++`, Python và VS Code trước khi chạy `setup.ps1`.

## Lưu ý

- Phải mở workspace từ thư mục `OOP_C++`, vì các đường dẫn cấu hình sử dụng `${workspaceFolder}`.
- Không đặt nhiều chương trình độc lập trong cùng một thư mục bài; mỗi chương trình nên có thư mục `ExXX` riêng.
- Tên thư mục bài không bắt buộc phải là `ExXX`, nhưng tất cả file `.cpp` trong cùng thư mục sẽ được compile vào một chương trình.
- Nếu `g++` không được tìm thấy, hãy kiểm tra MinGW-w64 đã được thêm vào biến môi trường `PATH`.
- File `input.txt` nằm ở thư mục gốc và được dùng chung cho các bài chạy bằng task.

## Kết thúc buổi học

Khi kết thúc một buổi học, có thể chạy file:

```text
end-session.bat
```

Script sẽ lần lượt:

1. Hiển thị tên máy, thời gian và nhánh Git hiện tại.
2. Liệt kê các file sinh ra như `build/`, `.exe`, `.o` và `.obj`.
3. Hỏi xác nhận trước khi xóa các file sinh ra.
4. Hiển thị các thay đổi của repository.
5. Hỏi xác nhận trước khi stage và commit.
6. Ghi thông tin cơ bản vào commit message.
7. Hỏi xác nhận riêng trước khi push lên GitHub.

Commit có dạng tương tự:

```text
study: session 2026-10-20_13-30 on DESKTOP-ABC123

Computer: DESKTOP-ABC123
Finished: 2026-10-20 13:30:12 +07:00
Branch: main
Changed files: 4
```

Script **không xóa source code, file PDF, `input.txt` hoặc thư mục bài tập**. Nếu commit đã tạo nhưng push thất bại, commit vẫn còn an toàn ở máy local và có thể push lại sau bằng:

```powershell
git push
```

Có thể bỏ qua dọn dẹp hoặc push khi chạy trực tiếp:

```powershell
.\end-session.ps1 -SkipCleanup
.\end-session.ps1 -SkipPush
```
