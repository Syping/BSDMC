BSDMC
=========

BSDMC is a fork of [MultiMC](https://github.com/MultiMC/MultiMC5), it's a custom launcher for Minecraft that allows you to easily manage multiple installations of Minecraft at once. It also allows you to easily install and remove mods by simply dragging and dropping. Here are the current [features](https://github.com/Syping/BSDMC/wiki#features) of BSDMC.


## Development
The project uses C++ and Qt5 as the language and base framework. This might seem odd in the Minecraft community, but allows using 25MB of RAM, where other tools use an excessive amount of resources for no reason.

We can do more, with less, on worse hardware and leave more resources for the game while keeping the launcher running and providing extra features.

### Easy Installation (bash, sudo and wget required)

    # Don't use root account!
    wget https://gist.githubusercontent.com/Syping/4dfdc3e3b79eedc38b2e5b99d876ac31/raw/c243e8b248c684898e8efa7155d0604e05d7edbb/bsdmc.bash -O bsdmc.bash
    chmod +x bsdmc.bash
    ./bsdmc.bash

### Building
If you want to build BSDMC yourself, check [BUILD.md](BUILD.md) for build instructions.

## License
Copyright &copy; 2013-2019 MultiMC Contributors  
Copyright &copy; 2020 BSDMC Contributors

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this program except in compliance with the License. You may obtain a copy of the License at [http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0).

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
