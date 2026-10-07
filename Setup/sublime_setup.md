### 1. Create the Build System

Open\: **Tools → Build System → New Build System…** and paste \:

```json
{
    "cmd": ["g++", "-std=c++23", "-Wall", "-Wextra", "-O2", "-DSUBLIME", "$file", "-o", "$file_base_name.exe", "&&", "$file_base_name.exe"],
    "working_dir": "$file_path",
    "selector": "source.c++",
    "shell": true
}
```
save the file as cpp23.sublime-build

### 2. Select the Build System
Go to\: **Tools → Build System → sublime-build**

### 3. Setup enviroment
- ```View -> Column-2```
- Selct right column and ```View -> Create new group```
