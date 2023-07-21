# Contributing

## Table of contents

- [Introduction](#introduction)
- [How to contribute](#how-to-contribute)
- [How to raise an issue](#how-to-raise-an-issue)

## Introduction

Thank you very much for being here! First of all, I want to let you know that contributions are more than welcome and really appreciated.

In case you want to contribute, even with a small bug fix, you will be featured into the credits list.

[Here](https://github.com/JustWhit3/osmanip/blob/main/TODO.md) you can find a list of todo features / updates that are planned and that you can implement to consistently contribute.

## How to contribute

To add your contribution, please follow these guidelines:

1) Fork your own copy of the repository.
2) Work on your changes / improvements in the forked repo.
3) **Test** if your changes / improvements are correctly implemented and all the other features are not compromised. For this latter requirement, please run this script:

```bash
./tests/all_tests.sh
```

and possibly update also the respective files with your news tests, if necessary.

5) Before submitting the code, reformat it using the [`.clang-format`](https://github.com/JustWhit3/osmanip/blob/main/.clang-format.md) file. Simply do:

```bash
.clang-format -i /path/to/file
```

5) Optional, but really appreciated: update the [documentation](https://justwhit3.github.io/osmanip/) (directly while writing the code) and the main [README](https://github.com/JustWhit3/osmanip/blob/main/README.md) with the new features you added.
6) Finally, make the pull request. The Doxygen page will be updated automatically.

Once your pull request will be submitted, I will carefully review it and, if it will be considered as an improvement, I will confirm it.

## How to raise an issue

If it is related to a bug, follow [this](https://github.com/JustWhit3/osmanip/tree/main/.github/ISSUE_TEMPLATE/bug_report.md) template.

If it is related to a feature request, follow [this](https://github.com/JustWhit3/osmanip/tree/main/.github/ISSUE_TEMPLATE/feature_request.md) template.