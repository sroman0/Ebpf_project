# eBPF Exploit Research Project

![polito](resources/logo_polito.jpg)

<details closed>
<summary><b>Table of Contents</b></summary>

&nbsp;• [Overview](#overview) <br>
&nbsp;• [Structure](#structure) <br>
&nbsp;• [Requirements](#requirements) <br>
&nbsp;• [Usage](#usage) <br>
&nbsp;• [Guidelines](#guidelines) <br>
&nbsp;• [Workflow](#workflow) <br>
&nbsp;• [Contribution](#contribution) <br>
&nbsp;• [References](#references) <br>
&nbsp;• [Authors](#authors) <br>
&nbsp;• [License](#license) <br>
&nbsp;• [Acknowledgments](#acknowledgments) <br>

 </details>

 ## Overview

This repository contains research artifacts, proof-of-concept (PoC) code, and exploitation attempts for vulnerabilities in the **eBPF verifier**. The goal of this project is to explore known exploitation techniques and apply them to unexploited vulnerabilities listed in the provided dataset.

This project is part of the [Security, Verification & Testing](https://didattica.polito.it/pls/portal30/gap.pkg_guide.viewGap?p_cod_ins=02TYAWQ&p_a_acc=2027&p_header=S&p_lang=IT&multi=N) 
course at **Politecnico di Torino**.

> **Navigation Tip**: This `README` provides a general overview of the project.
> For detailed documentation, check the specific `README` files in each directory ([see Table of Contents above](#table-of-contents)).
> Each subdirectory contains in-depth information about its specific components.
>
> ---

## Structure

```text
/
├── pocs/
│   ├── CVE-YYYY-XXXX-poc.c
│   ├── CVE-YYYY-XXXX-poc.log
│   └── ...
├── exploits/
│   ├── CVE-YYYY-XXXX-exploit.c
│   ├── CVE-YYYY-XXXX-exploit.log
│   └── ...
├── docs/
│   ├── analysis-CVE-YYYY-XXXX.md
│   ├── methodology.md
│   └── notes.md
├── tools/
│   ├── build.sh
│   ├── run_tests.sh
│   └── util_helpers/
├── WORKED_VULNERABILITIES.csv
├── README.md
└── .gitignore
```

## Requirements

- Ubuntu 20.04 or later
- Linux kernel with eBPF support (≥ 5.8 recommended)
- LLVM & Clang (≥ 11)
- libbpf / BCC
- `bpftool` for runtime inspection

### Dependencies

```bash
sudo apt update
sudo apt install -y \
  build-essential \
  clang llvm llvm-dev \
  libbpf-dev libelf-dev \
  bpftool
```

---

## Usage

### Compile a PoC

```bash
cd pocs
make CVE-YYYY-XXXX-poc
```

Or manually:

```bash
clang -O2 -target bpf -c CVE-YYYY-XXXX-poc.c -o CVE-YYYY-XXXX-poc.o
```

### Run PoC / Exploit

```bash
sudo ./tools/run_tests.sh CVE-YYYY-XXXX
```

### Inspect eBPF State

```bash
sudo bpftool prog show
sudo bpftool map show
```

---

## Guidelines

Each vulnerability analysis in `docs/` must include:

1. **CVE Summary**  
   Description, affected kernel versions, root cause.
2. **Dataset Entry**  
   Relevant row extracted from the provided Excel file.
3. **PoC Development**  
   - Source code
   - Build and execution instructions
   - Logs and kernel output
4. **Exploit Attempt**  
   - Exploitation strategy
   - Constraints and assumptions
   - Final exploit or failure explanation
5. **Verifier Behavior Analysis**  
   - How the verifier processed the program
   - Weakness or missing checks
6. **Test Environment**  
   - Kernel version
   - Configuration options
   - Toolchain versions

---

## Workflow

1. Filter the dataset for vulnerabilities tagged with **verifier**.
2. Select CVEs with no known exploit and no prior analysis.
3. Implement a minimal **PoC** to validate the issue.
4. Observe verifier behavior using kernel logs and `bpftool`.
5. Attempt exploitation using known techniques:
   - Pointer misvalidation
   - Out-of-bounds access
   - Verifier state confusion
   - Type or bounds inference errors
6. Iteratively refine the approach and **document every outcome**.

---

## Contribution

1. Fork the repository
2. Add PoC, documentation, and logs for a new CVE
3. Submit a pull request with reproducible results

---

## References

- Linux kernel eBPF documentation
- `bpftool` manual
- eBPF verifier internals research
- CVE databases



## Authors

| Name              | GitHub                                                                                                               | LinkedIn                                                                                                                                  | Email                                                                                                            |
| ----------------- | -------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- 
| Simone Romano     | [![GitHub](https://img.shields.io/badge/GitHub-Profile-informational?logo=github)](https://github.com/sroman0)       | [![LinkedIn](https://img.shields.io/badge/LinkedIn-Profile-blue?logo=linkedin)](https://www.linkedin.com/in/simone-romano-383277307/)     | [![Email](https://img.shields.io/badge/Email-Send-blue?logo=gmail)](mailto:simone.romano2@studenti.polito.it)    |


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- **Riccardo Sisto** ([riccardo.sisto@polito.it](mailto:riccardo.sisto@polito.it)): the professor supervising our work and the primary point of reference for the project.
- **Rosario Rizza** ([rosario.rizza@polito.it](mailto:rosario.rizza@polito.it)): phd candidate supervisor of the project
<div align="right">
<a href="#top">Back to top</a>
</div>
