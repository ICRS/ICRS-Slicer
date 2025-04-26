# ICRS Slicer

<br>ICRS Slicer is an open source slicer for FDM printers, forked from Orca Slicer. made for the Imperial College Robotics Society Lab.

## Follow Us

Stay connected with us:
[Imperial College Robotics](https://linktr.ee/icrobotics)

# Main features

- Auto-calibration for all printers
- Sandwich (inner-outer-inner) mode - An improved version of the `External Perimeters First` mode
- [Precise wall](https://github.com/SoftFever/OrcaSlicer/wiki/Precise-wall)
- Polyholes conversion support: [SuperSlicer Wiki: Polyholes](https://github.com/supermerill/SuperSlicer/wiki/Polyholes)
- Klipper support
- More granular controls
- Additional features can be found in the [change notes](https://github.com/SoftFever/OrcaSlicer/releases/)

# Wiki

The wiki below aims to provide a detailed explanation of the slicer settings, including how to maximize their use and how to calibrate and set up your printer.

Please note that the wiki is a work in progress. We appreciate your patience as we continue to develop and improve it!

**[Access the wiki here](https://github.com/SoftFever/OrcaSlicer/wiki)**

# How to compile

### Windows 64-bit

- Tools needed: Visual Studio 2019, Cmake, git, git-lfs, Strawberry Perl.
  - You will require cmake version 3.14 or later, which is available [on their website](https://cmake.org/download/).
  - Strawberry Perl is [available on their GitHub repository](https://github.com/StrawberryPerl/Perl-Dist-Strawberry/releases/).
- Run `build_release.bat` in `x64 Native Tools Command Prompt for VS 2019`
- Note: Don't forget to run `git lfs pull` after cloning the repository to download tools on Windows

### Mac 64-bit

- Tools needed: Xcode, Cmake, git, gettext, libtool, automake, autoconf, texinfo
  - You can install most of them by running `brew install cmake gettext libtool automake autoconf texinfo`
  - If you haven't since upgrading Xcode, start Xcode and install macOS build support.
- run `build_release_macos.sh`
- open `build_arm64/OrcaSlicer/OrcaSlicer.app`
- To build and debug in Xcode:
  - run `Xcode.app`
  - open `` build_`arch`/OrcaSlicer.Xcodeproj ``
  - menu bar: Product => Scheme => OrcaSlicer
  - menu bar: Product => Scheme => Edit Scheme...
    - Run => Info tab => Build Configuration: `RelWithDebInfo`
    - Run => Options tab => Document Versions: uncheck `Allow debugging when browsing versions`
  - menu bar: Product => Run

### Linux (All Distros)

- Docker
  - Dependencies: Docker [Installation Instructions](https://www.docker.com/get-started/), git
  - clone this repository `git clone https://github.com/SoftFever/OrcaSlicer`
  - run `cd OrcaSlicer`
  - run `./DockerBuild.sh`
  - To run OrcaSlicer:
    - run `./DockerRun.sh`
      - For most common errors, open `DockerRun.sh` and read the comments.
- Ubuntu
  - Dependencies **Will be auto installed with the shell script**: `libmspack-dev libgstreamerd-3-dev libsecret-1-dev libwebkit2gtk-4.0-dev libosmesa6-dev libssl-dev libcurl4-openssl-dev eglexternalplatform-dev libudev-dev libdbus-1-dev extra-cmake-modules libgtk2.0-dev libglew-dev libudev-dev libdbus-1-dev cmake git texinfo`
  - run 'sudo ./BuildLinux.sh -u'
  - run './BuildLinux.sh -dsi'

## Exporting

It is preferred to build on docker, then export the appImage to be run on the local Lab machine.

Once you have run `./DockerBuild.sh`. run `./DockerRun.sh` to start the docker container.

then find the container ID eg `b3db45eb4197`

then to export the appImage run `docker cp <container ID>:OrcaSlicer/build/ ~/Downloads/orca` this will create a folder called `orca` in your downloads folder where which you will find the appImage.

This appImage will be named like `OrcaSlicer_Linux_V2.3.1-dev.AppImage` and can be run on any Linux machine.

Use a USB to transfer the appImage to the lab machine. and place it in `~/.local/OrcaSlicer_ubu64.AppImage` this will then be linked to the `.Application` file and will appear in the applications menu asn taskbar icon.

# Supports

**Orca Slicer** is an open-source project and I'm deeply grateful to all my sponsors and backers.
Their generous support enables me to purchase filaments and other essential 3D printing materials for the project.
Thank you! :)

## Support The creators of Orca Slicer

<a href="https://github.com/sponsors/SoftFever"><img src="https://img.shields.io/static/v1?label=Sponsor&message=%E2%9D%A4&logo=GitHub&color=%23fe8e86" width="130"></a>

<a href="https://ko-fi.com/G2G5IP3CP"><img src="https://ko-fi.com/img/githubbutton_sm.svg" width="200"></a>

[![PayPal](https://img.shields.io/badge/PayPal-00457C?style=for-the-badge&logo=paypal&logoColor=white)](https://paypal.me/softfever3d)

## Some background

OrcaSlicer was originally forked from Bambu Studio, it was previously known as BambuStudio-SoftFever.

[Bambu Studio](https://github.com/bambulab/BambuStudio) is forked from [PrusaSlicer](https://github.com/prusa3d/PrusaSlicer) by Prusa Research, which is from [Slic3r](https://github.com/Slic3r/Slic3r) by Alessandro Ranellucci and the RepRap community.
Orca Slicer incorporates a lot of features from [SuperSlicer](https://github.com/supermerill/SuperSlicer) by @supermerill
Orca Slicer's logo is designed by community member Justin Levine(@freejstnalxndr)

# License

ICRS Slicer is licensed under the GNU Affero General Public License, version 3. ICRS Slicer is based on Orca Studio by SoftFever.

Orca Slicer is licensed under the GNU Affero General Public License, version 3. Orca Slicer is based on Bambu Studio by BambuLab.

Bambu Studio is licensed under the GNU Affero General Public License, version 3. Bambu Studio is based on PrusaSlicer by PrusaResearch.

PrusaSlicer is licensed under the GNU Affero General Public License, version 3. PrusaSlicer is owned by Prusa Research. PrusaSlicer is originally based on Slic3r by Alessandro Ranellucci.

Slic3r is licensed under the GNU Affero General Public License, version 3. Slic3r was created by Alessandro Ranellucci with the help of many other contributors.

The GNU Affero General Public License, version 3 ensures that if you use any part of this software in any way (even behind a web server), your software must be released under the same license.

Orca Slicer includes a pressure advance calibration pattern test adapted from Andrew Ellis' generator, which is licensed under GNU General Public License, version 3. Ellis' generator is itself adapted from a generator developed by Sineos for Marlin, which is licensed under GNU General Public License, version 3.

The Bambu networking plugin is based on non-free libraries from BambuLab. It is optional to the Orca Slicer and provides extended functionalities for Bambulab printer users.
