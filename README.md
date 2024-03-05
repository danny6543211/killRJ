# killRJ

## 简介

killRJ 是一个自动登录且关闭校园网锐捷客户端的脚本，用来解决客户端的多IP限制。

## 安装

在开始之前，请确保已记住账号密码且开启登陆后自动连接，并确保已安装以下软件和环境：
- Python 运行环境

### 步骤

1. **配置锐捷客户端的位置：**

    在 `ini.py` 文件中找到以下代码：

    ```python
    # 在 ini.py 文件中设置锐捷客户端路径
    RJ_client_path = "C:/path/to/your/RJ/client"
    ```

    将 `"C:/path/to/your/RJ/client"` 替换为你的锐捷客户端的实际路径。

2. **安装依赖并构建项目：**

    在命令行中执行以下命令：

    ```bash
    pip install -r requirements.txt
    python.exe setup.py build
    ```

## 使用

构建项目后，你可以在 build 文件夹中找到 killRJ.exe，并使用管理员权限运行它。