/* From: board-n1-pmic.c */
/* n1 because my device is the n1awifi variant (SM-P600) */
/* This information may differ for other devices that utilize the UNIVERSAL5420 board, */
/* such as the v1 (Note Pro 12.2), or the Note 3 SM-N900 */

#include "exynos5420.dtsi"
#include "exynos5420-pinctrl.dtsi"

&hsi2c_7 {
	max77802@09 {
		compatible = "maxim,max77802";
		interrupt-parent = <&wakeup_eint>;
		interrupts = <26 0>;
		reg = <0x09>;
		#address-cells = <1>;
		#size-cells = <0>;

		regulators {
			max77802_buck1_reg: BUCK1 {
				regulator-compatible = "BUCK1";
				regulator-name = "vdd_mif";
				regulator-always-on;
				regulator-boot-on;
				ops-mask = "voltage", "status";
				regulator-min-microvolt = <700000>;
				regulator-max-microvolt = <1300000>;
				regulator-state-mem {
					regulator-uV = <1100000>;
					regulator-mode-normal;
					regulator-mem-off;
				};
				consumers {
					1 {
						regulator-consumer-supply = "vdd_mif";
					};
				};
			};

			max77802_buck2_reg: BUCK2 {
				regulator-compatible = "BUCK2";
				regulator-name = "vdd_arm";
				regulator-apply-uV;
				regulator-always-on;
				regulator-boot-on;
				ops-mask = "voltage", "status";
				regulator-min-microvolt = <800000>;
				regulator-max-microvolt = <1500000>;
				regulator-state-mem {
					regulator-mem-off;
				};
				consumers {
					1 {
						regulator-consumer-supply = "vdd_arm";
					};
				};
			};

			max77802_buck3_reg: BUCK3 {
				regulator-compatible = "BUCK3";
				regulator-name = "vdd_int";
				regulator-always-on;
				regulator-boot-on;
				regulator-apply-uV;
				ops-mask = "voltage", "status";
				regulator-min-microvolt = <800000>;
				regulator-max-microvolt = <1400000>;
				regulator-state-mem {
					regulator-uV = <1100000>;
					regulator-mode-normal;
					regulator-mem-off;
				};
				consumers {
					1 {
						regulator-consumer-supply = "vdd_int";
					};
				};
			};

			max77802_buck4_reg: BUCK4 {
				regulator-compatible = "BUCK4";
				regulator-name = "vdd_g3d";
				regulator-always-on;
				regulator-boot-on;
				regulator-apply-uV;
				ops-mask = "voltage", "status";
				regulator-min-microvolt = <700000>;
				regulator-max-microvolt = <1400000>;
				regulator-state-mem {
					regulator-uV = <1100000>;
					regulator-mode-normal;
					regulator-mem-off;
				};
				consumers {
					1 {
						regulator-consumer-supply = "vdd_g3d";
					};
				};
			};

			max77802_buck6_reg: BUCK6 {
				regulator-compatible = "BUCK6";
				regulator-name = "vdd_kfc";
				regulator-always-on;
				regulator-boot-on;
				ops-mask = "voltage", "status";
				regulator-min-microvolt = <800000>;
				regulator-max-microvolt = <1500000>;
				regulator-state-mem {
					regulator-mem-off;
				};
				consumers {
					1 {
						regulator-consumer-supply = "vdd_kfc";
					};
				};
			};

			max77802_ldo2_reg: LDO2 {
				regulator-name ="vmem2_1.2v_ap";
				regulator-always-on;
				regulator-min-microvolt = <1200000>;
				regulator-max-microvolt = <1200000>;
			};

			max77802_ldo3_reg: LDO3 {
				regulator-compatible = 	"vcc_1.8v_ap", "spi2.0", "wm5102-codec", "AVDD,spi2.0", 
										"LDOVDD,spi2.0", "DBVDD1,spi2.0", "CPVDD,wm5102-codec",
										"DBVDD2,wm5102-codec", "DBVDD3,wm5102-codec",
										"SPKVDDL,wm5102-codec", "SPKVDDR,wm5102-codec";
				regulator-name = "vcc_1.8v_ap";
				regulator-always-on;
				regulator-min-microvolt = <1800000>;
				regulator-max-microvolt = <1800000>;
			};

			max77802_ldo4_reg: LDO4 {
				regulator-compatible = "vqmmc,dw_mmc.2", "vqmmc", "dw_mmc.2";
				regulator-name = "vmmc2_2.8v_ap"
				regulator-always-on;
				regulator-min-microvolt = <1800000>;
				regulator-max-microvolt = <1800000>;
			};


			max77802_ldo5_reg: LDO5 {
				regulator-name = 
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
			};

			max77802_ldo6_reg: LDO6 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo7_reg: LDO7 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo8_reg: LDO8 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo9_reg: LDO9 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo10_reg: LDO10 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo11_reg: LDO11 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo12_reg: LDO12 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo14_reg: LDO14 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo15_reg: LDO16 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};
			
			max77802_ldo17_reg: LDO17 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};
			
			max77802_ldo18_reg: LDO18 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};
			
			max77802_ldo19_reg: LDO19 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};
			
			max77802_ldo23_reg: LDO23 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo24_reg: LDO24 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo25_reg: LDO25 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo26reg: LDO26 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo27_reg: LDO27 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo28_reg: LDO28 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo29_reg: LDO29 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo30_reg: LDO30 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo32_reg: LDO32 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo33_reg: LDO33 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};

			max77802_ldo35_reg: LDO35 {
				regulator-always-on;
				regulator-min-microvolt = <>;
				regulator-max-microvolt = <>;
				regulator-name = 
			};
		};
	};
};