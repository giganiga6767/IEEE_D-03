# 🔌 AI-Enabled Smart Grid Monitoring System
### Envision 2025-26 · NIT Karnataka IEEE Student Branch · Team D-03

![Python](https://img.shields.io/badge/Python-3.10+-3776AB?style=flat&logo=python&logoColor=white)
![MATLAB](https://img.shields.io/badge/MATLAB-Simulink-orange?style=flat&logo=mathworks)
![Streamlit](https://img.shields.io/badge/Dashboard-Streamlit-FF4B4B?style=flat&logo=streamlit)
![ML](https://img.shields.io/badge/ML-XGBoost%20%7C%20LSTM%20%7C%20ANN-00C853?style=flat)
![License](https://img.shields.io/badge/License-MIT-blue?style=flat)

---

## 📌 Overview

An end-to-end **AI-powered smart grid monitoring platform** that combines real-time anomaly detection, short-term load forecasting, predictive maintenance, and automatic power factor correction (APFC) into a single unified system — visualized through a live Streamlit dashboard.

Traditional grid monitoring systems are purely reactive — they alarm only after thresholds are crossed. This project introduces a **proactive, predictive** approach using machine learning and a hardware-in-loop APFC simulation built in MATLAB/Simulink.

---

## 🏗️ System Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                    DATA GENERATION                          │
│   Synthetic 30-day smart grid data · 15-min intervals      │
│   Day/night load patterns · 2% injected fault anomalies    │
└──────────────────────────┬──────────────────────────────────┘
                           │
        ┌──────────────────┼──────────────────┐
        ▼                  ▼                  ▼
┌──────────────┐  ┌──────────────┐  ┌──────────────────────┐
│   ANOMALY    │  │     LOAD     │  │    PREDICTIVE        │
│  DETECTION   │  │ FORECASTING  │  │    MAINTENANCE       │
│ Isolation    │  │ XGBoost /    │  │  Random Forest       │
│   Forest     │  │  LSTM / ANN  │  │  Health Scoring      │
└──────┬───────┘  └──────┬───────┘  └──────────┬───────────┘
       │                 │                      │
       └─────────────────┴──────────────────────┘
                         │
              ┌──────────▼──────────┐
              │  STREAMLIT DASHBOARD │
              │  Live Monitor        │
              │  Load Forecasting    │
              │  Equipment Health    │
              └─────────────────────┘
                         
┌─────────────────────────────────────────────────────────────┐
│              APFC SUBSYSTEM (MATLAB/Simulink)               │
│  CT/PT → Q&PF Measurement → Microcontroller → Cap Banks    │
└─────────────────────────────────────────────────────────────┘
```

---

## ✨ Features

### ⚡ Automatic Power Factor Correction (APFC)
- Continuously measures grid V & I via CT/PT sensors
- Computes active power P, reactive power Q, and instantaneous PF
- **Optimized switching algorithm** across 2⁴ = 16 capacitor bank combinations
- True Load Reconstruction prevents over/under-compensation
- **100 VAR hysteresis band** eliminates breaker chatter
- **1.2× penalty** for over-compensation (prevents leading PF)
- Result: PF corrected from ~0.6–0.8 → **0.98+**

### 🔍 Anomaly Detection
- **Isolation Forest** (unsupervised) — no labeled fault data required
- Detects voltage faults and power factor degradation in real time
- Precision: **0.93** · Recall: **0.95** · F1-Score: **0.94**

### 📈 Load Forecasting
- 3 models benchmarked: **XGBoost**, **ANN**, **LSTM**
- Short-term forecasting: 15 minutes ahead
- Targets: Active power (kW) and Reactive power (kVAR)

| Model    | R² (Reactive) | MAE (Reactive) | R² (Active) | MAE (Active) |
|----------|--------------|----------------|-------------|--------------|
| XGBoost  | **0.997**    | **0.191 kVAR** | **1.000**   | **0.073 kW** |
| ANN      | 0.987        | 0.706 kVAR     | 0.991       | 1.260 kW     |
| LSTM     | 0.847        | 2.506 kVAR     | 0.958       | 2.694 kW     |

> **Key finding:** XGBoost outperforms deep learning models on tabular smart grid data with explicit feature engineering.

### 🔧 Predictive Maintenance
- **Random Forest Regressor** predicts equipment degradation level (0–1)
- Rolling window features from historical electrical parameters
- 4-hour rolling average of PF accounts for **91% of feature importance**
- MAE: **0.069** · RMSE: **0.113** · R²: **0.908**

| Health Score | Status | Action |
|-------------|--------|--------|
| 0.0 – 0.3   | 🟢 Healthy | No action required |
| 0.3 – 0.7   | 🟡 Early Degradation | Schedule inspection |
| 0.7 – 1.0   | 🔴 Critical | Immediate maintenance |

### 📊 Live Streamlit Dashboard
Three-tab web interface:
- **Live Monitor** — real-time gauges, anomaly alerts, scrolling graphs
- **Load Forecasting** — predicted vs actual plots, APFC recommendations
- **Equipment Health** — degradation gauge, health score, trend graphs

---

## 🛠️ Tech Stack

| Category | Technology |
|----------|-----------|
| Data Handling | NumPy, Pandas |
| Visualization | Matplotlib, Plotly |
| ML / DL | Scikit-learn, TensorFlow/Keras, XGBoost |
| Dashboard | Streamlit |
| Simulation | MATLAB / Simulink |
| Hardware Interface | Arduino, CT/PT Sensors |

---

## 📂 Repository Structure

```
AI-Enabled-Smart-Grid/
│
├── data/
│   ├── generate_data.py          # Synthetic smart grid data generator
│   └── smart_grid_data.csv       # 30-day · 15-min interval dataset
│
├── apfc/
│   ├── APFC_Simulink.slx         # MATLAB/Simulink APFC model
│   └── apfc_logic.m              # Microcontroller switching algorithm
│
├── models/
│   ├── anomaly_detection.py      # Isolation Forest model
│   ├── load_forecasting.py       # XGBoost / ANN / LSTM training
│   └── predictive_maintenance.py # Random Forest health scoring
│
├── dashboard/
│   └── app.py                    # Streamlit dashboard (3 tabs)
│
├── notebooks/
│   ├── EDA.ipynb                 # Exploratory data analysis
│   ├── model_benchmarking.ipynb  # XGBoost vs ANN vs LSTM comparison
│   └── results_visualization.ipynb
│
├── requirements.txt
└── README.md
```

---

## 🚀 Getting Started

### Prerequisites
- Python 3.10+
- MATLAB R2023a+ with Simulink (for APFC simulation)

### Installation

```bash
# Clone the repository
git clone https://github.com/ReubenAbrahamJacob/AI-Enabled-Smart-Grid-Monitoring-System.git
cd AI-Enabled-Smart-Grid-Monitoring-System

# Install dependencies
pip install -r requirements.txt
```

### Running the Dashboard

```bash
streamlit run dashboard/app.py
```

### Generating Synthetic Data

```bash
python data/generate_data.py
```

### Training Models

```bash
# Anomaly Detection
python models/anomaly_detection.py

# Load Forecasting (trains all 3 models)
python models/load_forecasting.py

# Predictive Maintenance
python models/predictive_maintenance.py
```

---

## 📊 Results

### APFC — Before vs After
| Metric | Before Correction | After Correction |
|--------|------------------|-----------------|
| Power Factor | 0.60 – 0.80 | **0.98+** |
| Current Phase | Lagging | In-phase |
| Reactive Power | High (uncompensated) | Locally compensated |

### Anomaly Detection
- Precision: **0.93** · Recall: **0.95** · F1: **0.94**

### Load Forecasting (XGBoost — best model)
- Reactive Power R²: **0.997**, MAE: **0.191 kVAR**
- Active Power R²: **1.000**, MAE: **0.073 kW**

### Predictive Maintenance
- R²: **0.908** · MAE: **0.069** · RMSE: **0.113**

---

## 🔮 Future Scope

- **Hardware-in-the-Loop (HIL):** Transition to real-time FPGA/RTOS testing
- **Edge AI:** Deploy Isolation Forest + XGBoost on NVIDIA Jetson / ESP32-S3
- **Multi-Agent RL:** Replace combination-testing logic with a reinforcement learning agent for optimal long-term switching
- **Cybersecurity Layer:** Anomaly detection for False Data Injection (FDI) attacks

---

## 👥 Team

**Mentors**
| Name | Roll No |
|------|---------|
| Reuben Abraham Jacob | 241EE147 |
| Namith AP | 241EE135 |
| Suhail Mohamed | 241EE234 |

**Mentees**
| Name | Roll No |
|------|---------|
| Vihaan Sunil | 251EC267 |
| Gandu Niranjan | 251EC216 |
| Abel Geo Tomy | 251EC201 |
| Addle Antony Jais | 251EE103 |
| Viren Garg | 251EE166 |

---

## 📚 References

- [Isolation Forest for Fault Detection in Electrical Systems](https://www.ijarst.in/public/uploads/paper/732951731349838.pdf)
- [MathWorks — Power Factor Correction](https://in.mathworks.com/discovery/power-factor-correction.html)
- [StatQuest — ML Fundamentals](https://www.youtube.com/@statquest)

---

## 🔗 Repositories

- **Main repo:** [ReubenAbrahamJacob/AI-Enabled-Smart-Grid-Monitoring-System](https://github.com/ReubenAbrahamJacob/AI-Enabled-Smart-Grid-Monitoring-System)
- **Mirror:** [namith17ap/Envision-26-D03](https://github.com/namith17ap/Envision-26-D03)

---

<div align="center">
  Made with ⚡ by Team D-03 · NIT Karnataka IEEE Student Branch · Envision 2025-26
</div>
